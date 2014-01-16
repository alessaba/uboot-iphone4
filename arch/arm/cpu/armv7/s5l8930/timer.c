/*
 * Copyright 2013, winocm <winocm@icloud.com>
 *
 * Board support for iPhone 4. Timer code.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation version 2.
 *
 * This program is distributed "as is" WITHOUT ANY WARRANTY of any
 * kind, whether express or implied; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <common.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/timer.h>

int timer_init(void)
{
	return 0;
}

u64 get_timer_us(ulong base)
{
	u32 tick_high, tick_low, tick_high2;

	do {
		tick_high = readl(S5L8930_TIMER_BASE + TIMER64_TICKS_HIGH);
		tick_low = readl(S5L8930_TIMER_BASE + TIMER64_TICKS_LOW);
		tick_high2 = readl(S5L8930_TIMER_BASE + TIMER64_TICKS_HIGH);
	} while(tick_high != tick_high2);

	return ((u64)tick_high << 32) | tick_low;
}

ulong get_timer(ulong base)
{
	ulong us = get_timer_us(0);
	us *= (1000000);
	us /= S5L8930_HZ_SEC;
	return us;
}

unsigned long long get_ticks(void)
{
	return get_timer(0);
}

ulong get_tbclk(void)
{
	return CONFIG_SYS_HZ;
}

void __udelay(unsigned long usec)
{
	ulong endtime;
	signed long diff;

	endtime = get_timer_us(0) + usec;

	do {
		ulong now = get_timer_us(0);
		diff = endtime - now;
	} while (diff >= 0);
}