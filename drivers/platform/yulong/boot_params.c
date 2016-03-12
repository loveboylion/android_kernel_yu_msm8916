/* Copyright (c) 2014, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <asm/setup.h>

#include <linux/export.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/string.h>

#include <linux/boot_params.h>

static int boot_mode = 0;
int get_boot_mode(void)
{
	return boot_mode;
}
EXPORT_SYMBOL(get_boot_mode);

static int __init init_boot_mode(char *s)
{
	if (!strncmp(s, "charger", 7)) {
		boot_mode = BOOT_MODE_CHARGER;
	} else if (!strncmp(s, "recovery", 8)) {
		boot_mode = BOOT_MODE_RECOVERY;
	} else {
		boot_mode = BOOT_MODE_SYSTEM;
	}

	return 0;
}
__setup("androidboot.mode=", init_boot_mode);

static int pon_batt_volt = 0;
int get_pon_batt_volt(void)
{
	return pon_batt_volt;
}
EXPORT_SYMBOL(get_pon_batt_volt);

static int __init init_pon_batt_volt(char *s)
{
	pon_batt_volt = (int) simple_strtol(s, NULL, 10);

	return 0;
}
__setup("pon_vol=", init_pon_batt_volt);
