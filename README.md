# �޽� 100 ��Դ IP �����Ϲ� FPGA �����¿����Ͳ���

�òֿ��� [wujian100_open](https://github.com/T-head-Semi/wujian100_open) �ķ�֧��ּ�������Ϲ� PDS ƽ̨�����޽� 100 ��Դ RISC-V ��������ԭ�����ļ���[���](README_old.md)�鿴��

## ���л���

  * Pango Design Suite Lite 2022.2
  * PGL50H-6FBG484 оƬ��MES50HP ������

## �Ⱦ�����

  * CKLINK ������
  * 12 �� PMOD ת CKLINK ����������

## �ļ��нṹ

**��ע�⣬�����ļ��е�ĳЩ�ļ����������ԭ���Ѿ�����ɾ�ģ������в��ġ�**

```
    |--case               // ģ���������
    |--doc                // �����ĵ�����������֧�Ŀ����ĵ�
    |--fpga               // ���� FPGA ����Ľű��ļ������� xdc ��
    |--lib                // �������ű������ڽ�Verilog��VHDL�������ɷ���ģ�͵Ľű��ļ����ýű��ļ������˷���������������Ϣ�����������·��������ѡ�����ʱ�����ڵ�
    |--regress            // �ع���Խ��
    |--sdk                // ����������߰�
    |--soc                // Soc RTL ����
    |--tb                 // ���Լ�������
    |--tools              // ����ű��������ļ�
    |--workdir            // ����Ŀ¼
    |--LICENSE
    |--README.md
```

## ϵͳ�ܹ�



## �� RTL ����Ĵ���

�� `./soc/param` �ļ����а����� RTL ��ƴ�����ⲿ������ͷ�ļ������� PDS ����������ļ���Ŀ¼���е��ļ�����˶��ڰ���������ͷ�ļ���Ҫô����ƴ������ͬһ��Ŀ¼�£�Ҫô����ƴ����е� `include    "[name]_params.v"`�������·�������磺`include    "./param/[name]_params.v"`��

����ϵͳʱ�� `PIN_EHS` �˿�Ҫ��Ϊ 20MHz�������Ҫʱ�ӷ�Ƶ IP �ˣ����������ڶ����ļ������޸���Ӧ������˿ڡ�
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


## ����������˿ڵļ�����

��������ӿڵ��������Դ� `./fpga/xdc/XC7A200T3B.xdc` �л�á������ҽ����½��� `./fpga/xdc/XC7A200T3B.xdc` �Ĺܽ�Լ�����ã�ʵ�ʵĹܽ�Լ��˵����[���](./doc/constraint.md)�鿴��

  | �˿� | ���� |
  |---------------|-----------------------|
  | PIN_EHS       |     ȫ������ʱ�� 20MHz  |
  | PAD_MCURST    |     ȫ�ָ�λ           |
  | PAD_JTAG_TCLK |     JTAG               |
  | PAD_JTAG_TMS  |     JTAG              |

  * GPIO��32 ����
  * PWM��13 ����
  * USI��3 �飻

### �ܽ�Լ����ע������

�� `XC7A200T3B.xdc` �����ǿ��Կ��������� `PAD_JTAG_TCLK` ����ʱ���źţ���δ����ȫ��ʱ���ź����������Ҫ���ָ�
```
set_property CLOCK_DEDICATED_ROUTE FALSE [get_nets PAD_JTAG_TCLK]
```
�Ա�ʵ�֣����ֲ��ߣ�ʱ���Լ��������硣

Ȼ����PDS ����֧�� Vivado �������ʽ�����Ҿ������ԣ�ֻ������� `PAD_JTAG_TCLK` �򱨴���ʾ������ `x_PAD_JTAG_TCLK.PAD`��������������
```
Place-0084: GLOBAL_CLOCK: the driver x_PAD_JTAG_TCLK.PAD_tri/opit_1 fixed at IOL_99_5 is unreasonable. Sub-optimal placement for a clock source and a clock buffer.
```

��������ǣ������� `PAD_JTAG_TCLK` ����ȫ�����ú��ԣ��� `.fdc` �ļ�������������
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
���ɽ������