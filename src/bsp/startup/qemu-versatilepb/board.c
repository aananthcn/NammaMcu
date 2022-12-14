#include <base_types.h>
#include <stdarg.h>
#include <stdio.h>

#include <osek.h>
#include <sg_appmodes.h>
#include <sg_counter.h>

#include <os_api.h>

#include <Mcu.h>


#include "qemu-versatilepb.h"


/* Serial console functions */
int console_fputc(const int c) {
        UART0DR = (unsigned int) (c);
        return c;
}


int console_fputs(const char *s) {
        int count = 0;

        while (*s != '\0') {
                console_fputc(*s);
                count++;
                s++;
        }

        return count;
}


#if 0
/* The timer on our QEMU system defaults to using a 1MHz reference. */
#define TIMER_CLK_TO_MILLISEC   (1000) /* 1 MHz == 1000 cycles / milli-sec */
#endif

#define CLOCK_SEC2MSEC          (1000) /* 1000ms = 1 sec */
/* System Clock = 1 MHz. The timer on our QEMU system defaults to using a 1MHz reference. */
#define SYSTEM_CLOCK_MHz        (1)

int bsp_setup_systimer(void) {
        u32 tick_count = OS_TICK_DURATION_ns * SYSTEM_CLOCK_MHz / CLOCK_SEC2MSEC;

        /* Timer0 counter reload value init */
        *((volatile u32*)(TIMER0_BASE+TIMERLOAD_OFFSET)) = tick_count;

        /* Timer0 as system tick counter: Enable | Int. En | 32bit mode */
        *((volatile u8*)(TIMER0_BASE+TIMERCTRL_OFFSET)) = 0xE2;

        /* Timer1 as free running counter: Enable | 32bit mode */
        *((volatile u8*)(TIMER1_BASE+TIMERCTRL_OFFSET)) = 0x82;

        return 0;
}

int bsp_get_usec_syscount(u32 *ucount) {
        u32 count;

        /* free running mode counts from 0xFFFFFFFF to 0, hence reversing it */
        count = (u32)0xFFFFFFFF - *((volatile u32*)(TIMER1_BASE+TIMERVALUE_OFFSET));

        /* convert to ucount so that the count value == 1 usec */
        *ucount = (u32)((count * 1000ull) / CLOCK_SEC2MSEC);

        return 0;
}


int bsp_sys_enable_interrupts() {
        /* Enable interrupts */
        VIC_INTENABLE = 1 << ISR_SN_TIMER01;

        return 0;
}


int bsp_console_init(void) {
        pr_log_init();

        return 0;
}


void Mcu_Init(const Mcu_ConfigType* ConfigPtr) {
        bsp_setup_systimer();
        bsp_console_init();
        bsp_sys_enable_interrupts();
}
