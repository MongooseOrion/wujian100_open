# 无剑 100 开源 IP 核在紫光 FPGA 环境下开发和部署

该仓库是 [wujian100_open](https://github.com/T-head-Semi/wujian100_open) 的分支，旨在利用紫光 PDS 平台部署无剑 100 开源 RISC-V 处理器。原自述文件可[点此](README_old.md)查看。

## 测试环境
  * Pango Design Suite Lite 2022.2
  * PGL50H-6FBG484 芯片部件编号

## 文件夹结构
```
    |--case               // 模块测试样例
    |--doc                // 开发文档
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