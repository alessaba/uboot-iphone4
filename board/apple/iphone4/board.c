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
#include <video_fb.h>

DECLARE_GLOBAL_DATA_PTR;

GraphicDevice gdev;

/*
 * Routine: a4_kp_init
 */
int a4_kp_init(void)
{
	return 0;
}

/*
 * Routine: a4_kp_tstc
 */
int a4_kp_tstc(void)
{
	return 0;
}

/*
 * Routine: a4_kp_getc
 */
int a4_kp_getc(void)
{
	return 0;
}

/*
 * Routine: video_hw_init
 * Description: Set up the GraphicDevice depending on sys_boot.
 */
void *video_hw_init(void)
{
	/* fill in Graphic Device */
	gdev.frameAdrs = 0x5f700000;
	gdev.winSizeX = 640;
	gdev.winSizeY = 960;
	gdev.gdfBytesPP = 4;
	gdev.gdfIndex = GDF_32BIT_X888RGB;
	memset((void *)gdev.frameAdrs, 0, 960 * 640 * 4);
	return (void *) &gdev;
}

/*
 * Routine: board_init
 * Description: Early hardware init.
 */
int board_init(void)
{
	gd->bd->bi_arch_number = MACH_TYPE_S5L8930;			/* Machine type for S5L8930. */
	gd->bd->bi_boot_params = LINUX_BOOT_PARAM_ADDR;	/* Load address. */
	
	return 0;
}

/*
 * Routine: misc_init_r
 * Description: Configure board specific parts.
 */
int misc_init_r(void)
{
	return 0;
}

/*
 * Routine: get_board_revision
 * Description: Return board revision.
 */
u32 get_board_rev(void)
{
	return 0xBEEF;
}


