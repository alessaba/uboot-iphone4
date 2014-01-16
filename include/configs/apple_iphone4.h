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

#ifndef __CONFIG_H
#define __CONFIG_H

/*
 * High level configuration options.
 */
#define CONFIG_SAMSUNG 1			/* in a Samsung core. */
#define CONFIG_S5L 1				/* in a S5L family */
#define CONFIG_S5L8930 1			/* in the 8930 family. */
#define CONFIG_IPHONE4 1			/* we are working with the iPhone 4. */

#include <asm/arch/cpu.h>

#define CONFIG_SYS_TEXT_BASE		0x40004000

/*
 * Display CPU and Board information
 */

/*
 * iBoot sets everything up for now.
 */
#undef CONFIG_USE_IRQ				/* no support for IRQs */
#define CONFIG_MISC_INIT_R
#define CONFIG_SKIP_LOWLEVEL_INIT

#define CONFIG_ENV_OVERWRITE

#define CONFIG_CMDLINE_TAG	/* enable passing kernel command line string */
#define CONFIG_INITRD_TAG			/* enable passing initrd */
#define CONFIG_REVISION_TAG			/* enable passing revision tag*/
#define CONFIG_SETUP_MEMORY_TAGS		/* enable memory tag */

#define CONFIG_ENV_IS_NOWHERE

#define CONFIG_SYS_NO_FLASH				1
#define CONFIG_SYS_CONSOLE_IS_IN_ENV 	1

/* commands to include */
#include <config_cmd_default.h>

/* commands not needed from config_cmd_default.h */
#undef CONFIG_CMD_FPGA			/* FPGA configuration Support */
#undef CONFIG_CMD_IMI			/* iminfo */
#undef CONFIG_CMD_NET			/* bootp, tftpboot, rarpboot */
#undef CONFIG_CMD_NFS			/* NFS support */
#undef CONFIG_CMD_SAVEENV		/* saveenv */
#undef CONFIG_CMD_SETGETDCR		/* DCR support on 4xx */


/*
 * Size of malloc() pool
 */
#define CONFIG_ENV_SIZE			(128 << 10)
#define CONFIG_UBI_SIZE			(512 << 10)
#define CONFIG_SYS_MALLOC_LEN		(CONFIG_ENV_SIZE + CONFIG_UBI_SIZE + \
					(128 << 10))

#define CONFIG_BOOTDELAY 30

#define CONFIG_SERIAL 1

#define CONFIG_CMDLINE_EDITING	1	/* add command line history */
#define CONFIG_AUTO_COMPLETE	1	/* add autocompletion support */

#define CONFIG_CMD_CLEAR	1	/* ANSI terminal clear screen command */


/*
 * Miscellaneous configurable options
 */
#define CONFIG_SYS_LONGHELP			/* undef to save memory */
#define CONFIG_SYS_HUSH_PARSER			/* use "hush" command parser */
#define CONFIG_SYS_PROMPT_HUSH_PS2	"> "
#define CONFIG_SYS_PROMPT		"[Apple iPhone4] # "
#define CONFIG_SYS_CBSIZE		256	/* Console I/O Buffer Size */
/* Print Buffer Size */
#define CONFIG_SYS_PBSIZE		(CONFIG_SYS_CBSIZE + \
						sizeof(CONFIG_SYS_PROMPT) + 16)
#define CONFIG_SYS_MAXARGS		16	/* max number of command args */
/* Boot Argument Buffer Size */
#define CONFIG_SYS_BARGSIZE		(CONFIG_SYS_CBSIZE)

#define CONFIG_BAUDRATE 		115200

#define CONFIG_SYS_LOAD_ADDR	0x44000000

#define CONFIG_SYS_INIT_RAM_ADDR	0x43000000
#define CONFIG_SYS_INIT_RAM_SIZE	0x8000
#define CONFIG_SYS_INIT_SP_ADDR		(CONFIG_SYS_INIT_RAM_ADDR + \
			CONFIG_SYS_INIT_RAM_SIZE - GENERATED_GBL_DATA_SIZE)

#define CONFIG_SYS_HZ 100

/* Environment information */
#define CONFIG_EXTRA_ENV_SETTINGS \
	"stdin=serial\0" \
	"stdout=serial\0" \
	"stderr=serial\0" \
	""

/*
 * Framebuffer
 */
/* Video console */
#define CONFIG_VIDEO
#define CONFIG_CFB_CONSOLE
#define CONFIG_CFB_CONSOLE_ANSI	/* Enable ANSI escape codes in framebuffer */
#define CONFIG_VIDEO_LOGO
#define CONFIG_VIDEO_SW_CURSOR
#define CONFIG_SPLASH_SCREEN

/* functions for cfb_console */
#define VIDEO_KBD_INIT_FCT		a4_kp_init()
#define VIDEO_TSTC_FCT			a4_kp_tstc
#define VIDEO_GETC_FCT			a4_kp_getc
#ifndef __ASSEMBLY__
int a4_kp_init(void);
int a4_kp_tstc(void);
int a4_kp_getc(void);
#endif

/*
 * Stack sizes
 *
 * The stack sizes are set up in start.S using the settings below
 */
#define CONFIG_STACKSIZE		(128 << 10) /* regular stack 128 KiB */

#define CONFIG_NR_DRAM_BANKS		1
#define CONFIG_SYS_SDRAM_BASE		0x40000000

#endif /* __CONFIG_H */

