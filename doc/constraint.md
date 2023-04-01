# 无剑 100 管脚约束说明

该约束方案仅作为参考，并不唯一。

## 环境

  * Pango Design Suite Lite 2022.2
  * PGL50H-6FBG484 芯片部件编号


## 时钟和复位

| 端口 | 硬件管脚编号 | 对应位置 |
| ------- | :-----: | ------ |
| clkin1 (PIN_EHS) | P20 | null |
| PAD_MCURST | H17 | KEY8 |

## JTAG

板上的 JTAG 接口已经用作 FPGA 比特流下载，因此采用 **PMOD** 接口来约束该 JTAG 引脚。

| 端口 | 硬件管脚编号 | 对应位置 |
| ----- | :-----: | ---------- |
| PAD_JTAG_TCLK | AB6 | 引脚 1 |
| PAD_JTAG_TMS | Y8 | 引脚 5 |

## GPIO

**请注意 GPIO 端口的总资源为 32 个。**

### 分配给按钮

| 端口 | 硬件管脚编号 | 对应位置 |
| ----- | :-----: | ---------- |
| PAD_GPIO_0 | K18 | KEY1 |
| PAD_GPIO_1 | L15 | KEY2 |
| PAD_GPIO_2 | J17 | KEY3 |
| PAD_GPIO_3 | K16 | KEY4 |

### 分配给 LED 灯

| 端口 | 硬件管脚编号 | 对应位置 |
| ----- | :-----: | ---------- |
| PAD_GPIO_4 | B2 | LED1 |
| PAD_GPIO_5 | A2 | LED2 |
| PAD_GPIO_6 | B3 | LED3 |
| PAD_GPIO_7 | A3 | LED4 |

### 分配给 SD 卡

| 端口 | 硬件管脚编号 | 对应位置 |
| ----- | :-----: | ---------- |
| PAD_GPIO_8 | C4 | NULL |
| PAD_GPIO_9 | A4 | NULL |
| PAD_GPIO_10 | D1 | NULL |
| PAD_GPIO_11 | D4 | NULL |
| PAD_GPIO_12 | D2 | NULL |
| PAD_GPIO_13 | D3 | NULL |

### 分配给 EEPROM

| 端口 | 硬件管脚编号 | 对应位置 |
| ----- | :-----: | ---------- |
| PAD_GPIO_14 | F15 | IIC_SCL |
| PAD_GPIO_15 | G8 | IIC_SDA |

### 分配给 40 PIN 外设接口

为了使用 3.3V 电源，所以反接。

| 端口 | 硬件管脚编号 | 对应位置 |
| ------ | :--------: | ----------- |
| PAD_GPIO_16 | AA4 | PIN36 |
| PAD_GPIO_17 | AB4 | PIN35 |
| PAD_GPIO_18 | Y5 | PIN34 |
| PAD_GPIO_19 | AB5 | PIN33 |
| PAD_GPIO_20 | W6 | PIN32 |
| PAD_GPIO_21 | Y6 | PIN31 |
| PAD_GPIO_22 | AA8 | PIN30 |
| PAD_GPIO_23 | AB8 | PIN29 |
| PAD_GPIO_24 | V7 | PIN28 |
| PAD_GPIO_25 | W8 | PIN27 |
| PAD_GPIO_26 | T8 | PIN26 |
| PAD_GPIO_27 | U8 | PIN25 |
| PAD_GPIO_28 | U9 | PIN24 |
| PAD_GPIO_29 | V9 | PIN23 |
| PAD_GPIO_30 | Y9 | PIN22 |
| PAD_GPIO_31 | AB9 | PIN21 |

## PWM

**请注意 PWM 端口总资源有 13 个**

### 分配给按钮

| 端口 | 硬件管脚编号 | 对应位置 |
| ------ | :--------: | ----------- |
| PAD_PWM_CH0 | J16 | KEY5 |
| PAD_PWM_CH1 | J19 | KEY6 |

### 分配给 PMOD 接口

| 端口 | 硬件管脚编号 | 对应位置 |
| ------ | :--------: | ----------- |
| PAD_PWM_CH2 | AA6 | PIN2 |
| PAD_PWM_CH3 | AB7 | PIN3 |
| PAD_PWM_CH4 | Y7 | PIN4 |
| PAD_PWM_CH5 | W9 | PIN6 |
| PAD_PWM_CH6 | U6 | PIN7 |
| PAD_PWM_CH7 | T7 | PIN8 |

### 分配给 40 PIN 外设接口
| 端口 | 硬件管脚编号 | 对应位置 |
| ------ | :--------: | ----------- |
| PAD_PWM_CH8 | U12 | PIN17 |
| PAD_PWM_CH9 | T12 | PIN18 |
| PAD_PWM_CH10 | U10 | PIN19 |
| PAD_PWM_CH11 | T10 | PIN20 |

### 分配给 LED 灯 

| 端口 | 硬件管脚编号 | 对应位置 |
| ------ | :--------: | ----------- |
| PAD_PWM_FAULT | C5 | LED5 |

## USI

**请注意 USI 资源有 3 组**

### 分配给 LED 灯

| 端口 | 硬件管脚编号 | 对应位置 |
| ------ | :--------: | ----------- |
| PAD_USI0_NSS | A5 | LED6 |
| PAD_USI0_SD1 | F7 | LED7 |

### 分配给 UART 

| 端口 | 硬件管脚编号 | 对应位置 |
| ------ | :--------: | ----------- |
| PAD_USI0_SCLK | R8 | UART0_RX |
| PAD_USI0_SD0 | R9 | UART0_TX |

### 分配给 40 PIN 扩展接口

| 端口 | 硬件管脚编号 | 对应位置 |
| ------ | :--------: | ----------- |
| PAD_USI1_NSS | AB10 | PIN9 |
| PAD_USI1_SCLK | AA10 | PIN10 |
| PAD_USI1_SD0 | Y10 | PIN11 |
| PAD_USI1_SD1 | W10 | PIN12 |
| PAD_USI2_NSS | T11 | PIN13 |
| PAD_USI2_SCLK | R11 | PIN14 |
| PAD_USI2_SD0 | Y12 | PIN15 |
| PAD_USI2_SD1 | W12 | PIN16 |

## 其余管脚

| 端口 | 硬件管脚编号 | 对应位置 |
| ------ | :--------: | ----------- |
| PIN_ELS | AB13 | PIN3 |
| POUT_ELS | Y13 | PIN4 |
| POUT_EHS | F8 | LED8 |
| pll_lock | AB11 | PIN5 |