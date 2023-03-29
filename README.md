# 无剑 100 开源 IP 核在紫光 FPGA 环境下开发和部署

该仓库是 [wujian100_open](https://github.com/T-head-Semi/wujian100_open) 的分支，旨在利用紫光 PDS 平台部署无剑 100 开源 RISC-V 处理器。原自述文件可[点此](README_old.md)查看。

## 运行环境

  * Pango Design Suite Lite 2022.2
  * PGL50H-6FBG484 芯片，MES50HP 开发板

## 先决条件

  * CKLINK 调试器
  * 12 针 PMOD 转 CKLINK 调试器排线

## 文件夹结构

**请注意，下述文件夹的某些文件或内容相比原版已经发生删改，请自行查阅。**

```
    |--case               // 模块测试样例
    |--doc                // 开发文档，包含本分支的开发文档
    |--fpga               // 配置 FPGA 所需的脚本文件，包括 xdc 等
    |--lib                // 仿真编译脚本，用于将Verilog或VHDL代码编译成仿真模型的脚本文件。该脚本文件包含了仿真器件的配置信息，例如仿真库的路径、编译选项、仿真时钟周期等
    |--regress            // 回归测试结果
    |--sdk                // 软件开发工具包
    |--soc                // Soc RTL 代码
    |--tb                 // 测试激励代码
    |--tools              // 仿真脚本和设置文件
    |--workdir            // 仿真目录
    |--LICENSE
    |--README.md
```

## 系统架构



## 对 RTL 代码的处理

在 `./soc/param` 文件夹中包含了 RTL 设计代码的外部参数化头文件，由于 PDS 会无视设计文件子目录当中的文件，因此对于包含参数的头文件，要么与设计代码放在同一级目录下，要么将设计代码中的 `include    "[name]_params.v"`加入相对路径，例如：`include    "./param/[name]_params.v"`。

由于系统时钟 `PIN_EHS` 端口要求为 20MHz，因此需要时钟分频 IP 核，将其例化在顶层文件，并修改相应的输入端口。
```ruby
//input           PIN_EHS;               
input           clkin1;
input           pll_lock;

// Add PLL(Clocking wizard) so that generate 20MHz
clk_wiz  x_clk_wiz (
  .clkin1      (clkin1),        // input: 50MHz
  .pll_lock    (pll_lock),      // output
  .clkout0     (PIN_EHS)        // output: 20MHz
);
```


## 对输入输出端口的简单描述

输入输出接口的描述可以从 `./fpga/xdc/XC7A200T3B.xdc` 中获得。这里我将大致借用 `./fpga/xdc/XC7A200T3B.xdc` 的管脚约束配置，实际的管脚约束说明可[点此](./doc/constraint.md)查看。

  | 端口 | 作用 |
  |---------------|-----------------------|
  | PIN_EHS       |     全局输入时钟 20MHz  |
  | PAD_MCURST    |     全局复位           |
  | PAD_JTAG_TCLK |     JTAG               |
  | PAD_JTAG_TMS  |     JTAG              |

  * GPIO：32 个；
  * PWM：13 个；
  * USI：3 组；

### 管脚约束的注意事项

在 `XC7A200T3B.xdc` 中我们可以看到，由于 `PAD_JTAG_TCLK` 属于时钟信号，但未接入全局时钟信号网，因此需要添加指令：
```
set_property CLOCK_DEDICATED_ROUTE FALSE [get_nets PAD_JTAG_TCLK]
```
以便实现（布局布线）时忽略检查该条网络。

然而，PDS 并不支持 Vivado 的命令格式，并且经过测试，只添加网络 `PAD_JTAG_TCLK` 或报错提示的网络 `x_PAD_JTAG_TCLK.PAD`，并不会解决错误：
```
Place-0084: GLOBAL_CLOCK: the driver x_PAD_JTAG_TCLK.PAD_tri/opit_1 fixed at IOL_99_5 is unreasonable. Sub-optimal placement for a clock source and a clock buffer.
```

解决方案是，将整个 `PAD_JTAG_TCLK` 网络全部设置忽略，在 `.fdc` 文件中添加下述命令：
```
define_attribute {n:PAD_JTAG_TCLK} {PAP_CLOCK_DEDICATED_ROUTE} {FALSE} 
define_attribute {n:x_PAD_JTAG_TCLK.PAD} {PAP_CLOCK_DEDICATED_ROUTE} {FALSE} 
define_attribute {n:x_PAD_JTAG_TCLK.ID} {PAP_CLOCK_DEDICATED_ROUTE} {FALSE} 
define_attribute {n:x_PAD_JTAG_TCLK.IEN} {PAP_CLOCK_DEDICATED_ROUTE} {FALSE} 
define_attribute {n:x_PAD_JTAG_TCLK.N2} {PAP_CLOCK_DEDICATED_ROUTE} {FALSE} 
define_attribute {n:x_PAD_JTAG_TCLK.N3} {PAP_CLOCK_DEDICATED_ROUTE} {FALSE} 
define_attribute {n:x_PAD_JTAG_TCLK.OD} {PAP_CLOCK_DEDICATED_ROUTE} {FALSE} 
define_attribute {n:x_PAD_JTAG_TCLK.OEN} {PAP_CLOCK_DEDICATED_ROUTE} {FALSE}
```
即可解决错误。