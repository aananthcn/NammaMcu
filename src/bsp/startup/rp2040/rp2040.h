#ifndef VERSATILEPB_H
#define VERSATILEPB_H

/* Register definitions for versatilepb board */

#include <base_types.h>


/* Interrupt Macros */
#define DISABLE_INTERRUPT       (0x00000000)
#define ENABLE_INTERRUPT        (0x00000000)


/* Interrupt Controller in RP2040 */
//==================================
#define SIO_BASE                (0xd0000000)
#define PPB_BASE                (0xe0000000)


/* Interrupt Control and State Register */
#define ICSR_OFFSET             0xed04
#define ICSR                    *((volatile u32*)(PPB_BASE + ICSR_OFFSET)))
/* Interrupt Set-Enable Register */
#define NVIC_ISER_OFFSET        0xe100
#define NVIC_ISER               (*((volatile u32*)(PPB_BASE + NVIC_ISER_OFFSET)))
/* Interrupt Clear-Enable Register */
#define NVIC_ICER_OFFSET        0xe180
#define NVIC_ICER               (*((volatile u32*)(PPB_BASE + NVIC_ICER_OFFSET)))



/* SysTick Registers */
#define SYST_CSR_OFFSET         (0xe010)
#define SYST_CSR                (*((volatile u32*)(PPB_BASE + SYST_CSR_OFFSET)))

#define SYST_RVR_OFFSET         (0xe014)
#define SYST_RVR                (*((volatile u32*)(PPB_BASE + SYST_RVR_OFFSET)))
#define SYST_CVR_OFFSET         (0xe018)
#define SYST_CVR                (*((volatile u32*)(PPB_BASE + SYST_CVR_OFFSET)))


/* Subsystem Resets */
#define RESETS_BASE             (0x4000c000)

#define RESET_CTRL              (*((volatile u32*)(RESETS_BASE + 0x0)))
#define RESET_WDSEL             (*((volatile u32*)(RESETS_BASE + 0x4)))
#define RESET_DONE              (*((volatile u32*)(RESETS_BASE + 0x8)))

#define SS_BIT_ADC              (1 << 0)
#define SS_BIT_BUSCTRL          (1 << 1)
#define SS_BIT_DMA              (1 << 2)
#define SS_BIT_I2C0             (1 << 3)
#define SS_BIT_I2C1             (1 << 4)
#define SS_BIT_IO_BANK0         (1 << 5)
#define SS_BIT_IO_QSPI          (1 << 6)
#define SS_BIT_JTAG             (1 << 7)
#define SS_BIT_PADS_BANK0       (1 << 8)
#define SS_BIT_PADS_QSPI        (1 << 9)
#define SS_BIT_PIO0             (1 << 10)
#define SS_BIT_PIO1             (1 << 11)
#define SS_BIT_PLL_SYS          (1 << 12)
#define SS_BIT_PLL_USB          (1 << 13)
#define SS_BIT_PWM              (1 << 14)
#define SS_BIT_RTC              (1 << 15)
#define SS_BIT_SPI0             (1 << 16)
#define SS_BIT_SPI1             (1 << 17)
#define SS_BIT_SYSCFG           (1 << 18)
#define SS_BIT_SYSINFO          (1 << 19)
#define SS_BIT_TBMAN            (1 << 20)
#define SS_BIT_TIMER            (1 << 21)
#define SS_BIT_UART0            (1 << 22)
#define SS_BIT_UART1            (1 << 23)
#define SS_BIT_USBCTRL          (1 << 24)


/* Clock & Oscillator Registers */
/*/================================
RP2040 External Clock: 12 MHz
RP2040 System Clock:  125 MHz (max)
================================/*/
#define XOSC_BASE               (0x40024000)

#define XOSC_CTRL_OFFSET        (0x00)
#define XOSC_CTRL               (*((volatile u32*)(XOSC_BASE + XOSC_CTRL_OFFSET)))
#define XOSC_FREQ_RANGE_1_15MHz (0xaa0)
#define XOSC_ENABLE             (0xfab << 12)
#define XOSC_DISABLE            (0xd1e << 12)

#define XOSC_STATUS_OFFSET      (0x04)
#define XOSC_STATUS             (*((volatile u32*)(XOSC_BASE + XOSC_STATUS_OFFSET)))

#define XOSC_STARTUP_OFFSET     (0x0C)
#define XOSC_STARTUP            (*((volatile u32*)(XOSC_BASE + XOSC_STATUS_OFFSET)))
#define XOSC_DELAY(x)           (x << 0)


/* SYS & USB PLL */
#define PLL_SYS_BASE            (0x40028000)
#define PLL_USB_BASE            (0x4002c000)
#define PLL_CS_OFFSET           (0x0)
#define PLL_PWR_OFFSET          (0x4)
#define PLL_FBDIV_INT_OFFSET    (0x8)
#define PLL_PRIM_OFFSET         (0xc)


/* Clocks */
#define CLOCKS_BASE             (0x40008000)
#define CLK_CTRL                (0x0)
#define CLK_DIV                 (0x4)
#define CLK_SELECTED            (0x8)

#define CLK_GPOUT0_CTRL         (*((volatile u32*)(CLOCKS_BASE + 0x0)))
#define CLK_GPOUT0_DIV          (*((volatile u32*)(CLOCKS_BASE + 0x4)))
#define CLK_GPOUT1_CTRL         (*((volatile u32*)(CLOCKS_BASE + 0xc)))
#define CLK_GPOUT1_DIV          (*((volatile u32*)(CLOCKS_BASE + 0x10)))
#define CLK_GPOUT2_CTRL         (*((volatile u32*)(CLOCKS_BASE + 0x18)))
#define CLK_GPOUT2_DIV          (*((volatile u32*)(CLOCKS_BASE + 0x1c)))
#define CLK_GPOUT3_CTRL         (*((volatile u32*)(CLOCKS_BASE + 0x24)))
#define CLK_GPOUT3_DIV          (*((volatile u32*)(CLOCKS_BASE + 0x28)))

#define CLK_REF_BASE            (CLOCKS_BASE + 0x30)
#define CLK_REF_CTRL            (*((volatile u32*)(CLK_REF_BASE + CLK_CTRL)))
#define CLK_REF_DIV             (*((volatile u32*)(CLK_REF_BASE + CLK_DIV)))
#define CLK_REF_SELECTED        (*((volatile u32*)(CLK_REF_BASE + CLK_SELECTED)))

#define CLK_SYS_BASE            (CLOCKS_BASE + 0x3c)
#define CLK_SYS_CTRL            (*((volatile u32*)(CLK_SYS_BASE + CLK_CTRL)))
#define CLK_SYS_DIV             (*((volatile u32*)(CLK_SYS_BASE + CLK_DIV)))
#define CLK_SYS_SELECTED        (*((volatile u32*)(CLK_SYS_BASE + CLK_SELECTED)))

#define CLK_PERI_CTRL           (*((volatile u32*)(CLOCKS_BASE + 0x48)))
#define PERI_AUXSRC(x)          (x << 5)
#define PERI_ENABLE             (1 << 11)

#define CLK_USB_BASE            (CLOCKS_BASE + 0x54)
#define CLK_ADC_BASE            (CLOCKS_BASE + 0x60)
#define CLK_RTC_BASE            (CLOCKS_BASE + 0x6C)




/* Raspberry Pi Pico (RP2040) Timer Register */
//============================================
#define TIMER_BASE              (0x40054000)
#define TIMEHW_OFFSET           (0x00)
#define TIMELW_OFFSET           (0x04)
#define TIMEHR_OFFSET           (0x08)
#define TIMELR_OFFSET           (0x0C)

#define TIMELR                  (*((volatile u32*)(TIMER_BASE + TIMELR_OFFSET)))


/* Watchdog - Timer derives clock from Watchdog */
#define WATCHDOG_BASE           (0x40058000)

#define WDG_CTRL                (*((volatile u32*)(WATCHDOG_BASE + 0x00)))
#define WDG_LOAD                (*((volatile u32*)(WATCHDOG_BASE + 0x04)))
#define WDG_REASON              (*((volatile u32*)(WATCHDOG_BASE + 0x08)))
#define WDG_TICK                (*((volatile u32*)(WATCHDOG_BASE + 0x2C)))


/* GPIO Registers */
#define GPIO_BASE               (0x40014000)
#define GET_GPIO_STATUS(n)      (*((volatile u32*)(GPIO_BASE + (2*(n))*4)))
#define GET_GPIO_CTRL(n)        (*((volatile u32*)(GPIO_BASE + ((2*(n))+1)*4)))
#define SET_GPIO_CTRL(n, val)   ((*((volatile u32*)(GPIO_BASE + ((2*(n))+1)*4))) = (val))

enum gpio_function {
        GPIO_FUNC_XIP = 0,
        GPIO_FUNC_SPI = 1,
        GPIO_FUNC_UART = 2,
        GPIO_FUNC_I2C = 3,
        GPIO_FUNC_PWM = 4,
        GPIO_FUNC_SIO = 5,
        GPIO_FUNC_PIO0 = 6,
        GPIO_FUNC_PIO1 = 7,
        GPIO_FUNC_GPCK = 8,
        GPIO_FUNC_USB = 9,
        GPIO_FUNC_NULL = 0xf,
};

#define PADS_BANK0_BASE         (0x4001c000)
#define GET_PAD_GPIO(n)         (*((volatile u32*)(PADS_BANK0_BASE + (((n)+1)*4))))
#define SET_PAD_GPIO(n, val)    ((*((volatile u32*)(PADS_BANK0_BASE + (((n)+1)*4)))) = (val))


/* SIO - Single-cycle IO */
#define SIO_BASE                (0xd0000000)

#define SIO_GPIO_IN             (*((volatile u32*)(SIO_BASE + 0x04)))
#define SIO_GPIO_OUT            (*((volatile u32*)(SIO_BASE + 0x10)))
#define SIO_GPIO_OE             (*((volatile u32*)(SIO_BASE + 0x20)))


/* UART / USART Registers */
//================================
#define UART0_BASE              (0x40034000)
#define UART1_BASE              (0x40038000)

#define UART_DR(base)           (*((volatile u32*)(base + 0x00)))
#define UART_RSR_ECR(base)      (*((volatile u32*)(base + 0x04)))
#define UART_FR(base)           (*((volatile u32*)(base + 0x18)))
#define UART_IBRD(base)         (*((volatile u32*)(base + 0x24)))
#define UART_FBRD(base)         (*((volatile u32*)(base + 0x28)))
#define UART_LCR_H(base)        (*((volatile u32*)(base + 0x2c)))
#define UART_CR(base)           (*((volatile u32*)(base + 0x30)))



/* SPI Registers*/
//========================
#define SPI0_BASE               (0x4003c000)
#define SPI1_BASE               (0x40040000)

// control registers
#define SSPCR0(base)            (*((volatile u32*)(base + 0x00)))
#define SSPCR1(base)            (*((volatile u32*)(base + 0x04)))
// data register
#define SSPDR(base)             (*((volatile u32*)(base + 0x08)))
// status register
#define SSPSR(base)             (*((volatile u32*)(base + 0x0c)))
#define SPI_BSY                 (1 << 4)
#define SPI_RNE                 (1 << 2)
#define SPI_TNF                 (1 << 1)
// clock prescalar
#define SSPCPSR(base)           (*((volatile u32*)(base + 0x10)))
// interrupt mask set/clear
#define SSPIMSC(base)           (*((volatile u32*)(base + 0x14)))
// raw interrupt status
#define SSPRIS(base)            (*((volatile u32*)(base + 0x18)))
// masked interrupt status
#define SSPMIS(base)            (*((volatile u32*)(base + 0x1c)))
// interrupt clear register
#define SSPICR(base)            (*((volatile u32*)(base + 0x20)))
// DMA control
#define SSPDMACR(base)          (*((volatile u32*)(base + 0x24)))
// peripheral ID registers
#define SSPPERIPHID0(base)      (*((volatile u32*)(base + 0xfe0)))
#define SSPPERIPHID1(base)      (*((volatile u32*)(base + 0xfe4)))
#define SSPPERIPHID2(base)      (*((volatile u32*)(base + 0xfe8)))
#define SSPPERIPHID4(base)      (*((volatile u32*)(base + 0xfec)))
// PrimeCell identification register
#define SSPPCELLID0(base)       (*((volatile u32*)(base + 0xff0)))
#define SSPPCELLID1(base)       (*((volatile u32*)(base + 0xff4)))


#endif
