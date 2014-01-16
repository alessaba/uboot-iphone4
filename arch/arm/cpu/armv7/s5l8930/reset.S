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

#include <asm/arch/cpu.h>
#include <linux/linkage.h>

ENTRY(reset_cpu)
	ldr		r1, =0xBF10202C
	ldr		r3, =0xBF102024
	movs	r0, #0
	movs	r2, #1
	str		r0, [r1]
	str		r2, [r3]
	ldr		r2, =0xBF102020
	mov		r3, #0x80000000
	str		r3, [r2]
	mov		r3, #4
	str		r3, [r1]
	str		r0, [r2]
_loop_forever:
	b	_loop_forever
ENDPROC(reset_cpu)
