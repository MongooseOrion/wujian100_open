# �޽� 100 ��Դ IP �����Ϲ� FPGA �����¿����Ͳ���

�òֿ��� [wujian100_open](https://github.com/T-head-Semi/wujian100_open) �ķ�֧��ּ�������Ϲ� PDS ƽ̨�����޽� 100 ��Դ RISC-V ��������ԭ�����ļ���[���](README_old.md)�鿴��

## ���л���

  * Pango Design Suite Lite 2022.2
  * PGL50H-6FBG484 оƬ��MES50HP ������

## �Ⱦ�����

  * CKLINK ������
  * �ܹ����� `TCK` �� `TMS` �˿ڵ�����

## �ļ��нṹ

**��ע�⣬�����ļ��е�ĳЩ�ļ����������ԭ���Ѿ�����ɾ�ģ������в��ġ�**

```
    |--case               // ģ���������
    |--doc                // �����ĵ�����������֧�Ŀ����ĵ�
    |--fpga               // ���� FPGA ����Ľű��ļ������� xdc ��
    |--lib                // �������ű������ڽ� Verilog �� VHDL �������ɷ���ģ�͵Ľű��ļ����ýű��ļ������˷���������������Ϣ�����������·��������ѡ�����ʱ�����ڵ�
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

��ע�⣬�˴���ģ�����ƽ���Ϊ�ܹ�������;��������ʵ�ʵ������ṹ������ EDA �������ɵ�����ģ��ṹΪ׼��

```
// input ָռ�õ� MASTER ͨ����output ָռ�õ� SLAVE ͨ����inout ָ˫��ͨ��

|-- wujian100_open_top                      // ϵͳ����
  |-- x_clk_wiz                             // ʱ��
  |-- x_main_bus_top (from x_pdu_top)       // һ�����ߣ�AHB��
    |-- x_ahb_matrix_7_12_main              // ���߿�������dec ��ʾ������룬arb ��ʾ�����ٲã�7 �� MASTER��12 �� SLAVE
    |-- x_main_mdummy_top0                  // [input] Dummy0 Master 
    |-- x_main_mdummy_top1                  // [input] Dummy1 Master 
    |-- x_main_mdummy_top2                  // [input] Dummy2 Master 
    |-- x_main_imemdummy_top0               // [output] Dummy IMEM
    |-- x_main_dmemdummy_top0               // [output] Dummy DMEM  
    |-- x_main_dummy_top0                   // [output] Dummy0
    |-- x_main_dummy_top1                   // [output] Dummy1
    |-- x_main_dummy_top2                   // [output] Dummy2
    |-- x_main_dummy_top3                   // [output] Dummy3
    |-- x_dmac_top                          // [inout] DMA
    |-- x_cpu_top                           // [input2:0] CPU
    |-- x_sms0_top (from x_retu_top)        // [output] DRAM0
    |-- x_sms1_top (from x_retu_top)        // [output] DRAM1
    |-- x_sms1_top (from x_retu_top)        // [output] DRAM2
    |-- x_isram_top (from x_retu_top)       // [output] ISRAM
    |-- x_sub_ls_top                        // [output] ��������
  |-- x_sub_ls_top (from x_pdu_top)         // �������ߣ�AHB��
    |-- x_sub_ls_top                        // ���߿�������1 �� MASTER��6 �� SLAVE
    |-- x_lsbus_dummy_top0                  // [output] Dummy0
    |-- x_lsbus_dummy_top1                  // [output] Dummy1
    |-- x_lsbus_dummy_top2                  // [output] Dummy2
    |-- x_lsbus_dummy_top3                  // [output] Dummy3
    |-- x_main_bus_top                      // [input] һ������
    |-- x_sub_apb0_top                      // [output] �������߱�� 0
    |-- x_sub_apb1_top                      // [output] �������߱�� 1
  |-- x_sub_apb0_top (from x_pdu_top)       // �������� 0��APB��
    |-- x_apb0_sub_top                      // ���߿���
    |-- x_tim0_sec_top                      // [] TIM0
    |-- x_tim2_sec_top                      // [] TIM2
    |-- x_tim4_sec_top                      // [] TIM4
    |-- x_tim6_sec_top                      // [] TIM6
    |-- x_usi0_sec_top                      // [] USI0
    |-- x_usi2_sec_top                      // [] USI2
    |-- x_wdt_sec_top                       // [] WDT
    |-- x_pwm_sec_top                       // [] PWM
    |-- x_apb0_dummy_top1                   // [] Dummy1
    |-- x_apb0_dummy_top2                   // [] Dummy2
    ...
    |-- x_apb0_dummy_top9                   // [] Dummy9
  |-- x_sub_apb1_top (from x_pdu_top)       // �������� 1��APB��
    |-- x_apb1_sub_top                      // ���߿���
    |-- x_tim1_sec_top                      // [] TIM1
    |-- x_tim3_sec_top                      // [] TIM3
    |-- x_tim5_sec_top                      // [] TIM5
    |-- x_tim7_sec_top                      // [] TIM7
    |-- x_usi1_sec_top                      // [] USI1
    |-- x_apb0_dummy_top1                   // [] Dummy1
    |-- x_apb0_dummy_top2                   // [] Dummy2
    ...
    |-- x_apb0_dummy_top8                   // [] Dummy8

// ���У�Dummy ��Ϊ�Զ���ģ���Ԥ���ӿ�
```

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

��������ӿڵ��������Դ� `./fpga/xdc/XC7A200T3B.xdc` �л�á��������ۺ��� `./fpga/xdc/XC7A200T3B.xdc` �� `./fpga/xdc/gensys2.xdc` �Ĺܽ�Լ�����ã�ʵ�ʵĹܽ�Լ��˵����[���](./doc/constraint.md)�鿴��

  | �˿� | ���� |
  |---------------|-----------------------|
  | PIN_EHS       |     ȫ������ʱ�� 20MHz  |
  | PAD_MCURST    |     ȫ�ָ�λ           |
  | PAD_JTAG_TCLK |     JTAG               |
  | PAD_JTAG_TMS  |     JTAG              |

  * GPIO��32 ����
  * PWM��13 ����
  * USI��3 �飻

�� `../doc/wujian100_open Userguide v1.0.docx` ���г��˸��˿ڵĶ��壬����Ҫ����һ������Լ���˿ڣ����� `UART`��

### �ܽ�Լ����ע������

�� `XC7A200T3B.xdc` �п��Կ��������� `PAD_JTAG_TCLK` ����ʱ���źţ���δ����ȫ��ʱ���ź����������Ҫ���ָ�
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