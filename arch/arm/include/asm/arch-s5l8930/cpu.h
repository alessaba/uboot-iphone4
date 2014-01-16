/*
 * Copyright 2013, winocm <winocm@icloud.com>
 *
 * Board support for iPhone 4.
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

#ifndef __S5L8930X_CPU_H
#define __S5L8930X_CPU_H

#define S5L_CPU_NAME		"S5L"

#define S5L8930_UART		0x82500000

#ifndef __ASSEMBLY__
#include <asm/io.h>

enum s3c24x0_uarts_nr {
	S3C24X0_UART0,
	S3C24X0_UART1,
};

static inline struct s3c24x0_uart
	*s3c24x0_get_base_uart(enum s3c24x0_uarts_nr n)
{
	return (struct s3c24x0_uart *)(S5L8930_UART + (n * 0x4000));
}

/* UART (see manual chapter 11) */
struct s3c24x0_uart {
	u32	ulcon;
	u32	ucon;
	u32	ufcon;
	u32	umcon;
	u32	utrstat;
	u32	uerstat;
	u32	ufstat;
	u32	umstat;
#ifdef __BIG_ENDIAN
	u8	res1[3];
	u8	utxh;
	u8	res2[3];
	u8	urxh;
#else /* Little Endian */
	u8	utxh;
	u8	res1[3];
	u8	urxh;
	u8	res2[3];
#endif
	u32	ubrdiv;
};
#endif

#endif /* __S5L8930X_CPU_H */