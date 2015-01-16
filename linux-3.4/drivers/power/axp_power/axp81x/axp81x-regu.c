/*
 * Regulators driver for allwinnertech AXP81X
 *
 * Copyright (C) 2014 allwinnertech Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include "../axp-regu.h"
#include "axp81x-regu.h"

/* Reverse engineered partly from Platformx drivers */
enum axp_regls{
	axp81x_vcc_dcdc1,
	axp81x_vcc_dcdc2,
	axp81x_vcc_dcdc3,
	axp81x_vcc_dcdc4,
	axp81x_vcc_dcdc5,
	axp81x_vcc_dcdc6,
	axp81x_vcc_dcdc7,

	axp81x_vcc_ldo1,
	axp81x_vcc_ldo2,
	axp81x_vcc_ldo3,
	axp81x_vcc_ldo4,
	axp81x_vcc_ldo5,
	axp81x_vcc_ldo6,
	axp81x_vcc_ldo7,
	axp81x_vcc_ldo8,
	axp81x_vcc_ldo9,
	axp81x_vcc_ldo10,
	axp81x_vcc_ldo11,
	axp81x_vcc_ldo12,
	axp81x_vcc_ldo13,
	axp81x_vcc_ldoio0,
	axp81x_vcc_ldoio1,
	axp81x_vcc_dc1sw,
};

static struct axp_regu_data axp81x_regu_data;
static struct axp_supply_data axp81x_supply_data = {
	{
		{
			.supply = axp81x_regu_data.axp_ldo1_data[0].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo1_data[1].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo1_data[2].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo1_data[3].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo1_data[4].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo1_data[5].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo1_data[6].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo1_data[7].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo1_data[8].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo1_data[9].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo1_data[10].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo1_data[11].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo1_data[12].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo1_data[13].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo1_data[14].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo1_data[15].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo1_data[16].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo1_data[17].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo1_data[18].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo1_data[19].supply,
		},
	},
	{
		{
			.supply = axp81x_regu_data.axp_ldo2_data[0].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo2_data[1].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo2_data[2].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo2_data[3].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo2_data[4].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo2_data[5].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo2_data[6].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo2_data[7].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo2_data[8].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo2_data[9].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo2_data[10].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo2_data[11].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo2_data[12].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo2_data[13].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo2_data[14].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo2_data[15].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo2_data[16].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo2_data[17].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo2_data[18].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo2_data[19].supply,
		},
	},
	{
		{
			.supply = axp81x_regu_data.axp_ldo3_data[0].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo3_data[1].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo3_data[2].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo3_data[3].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo3_data[4].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo3_data[5].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo3_data[6].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo3_data[7].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo3_data[8].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo3_data[9].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo3_data[10].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo3_data[11].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo3_data[12].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo3_data[13].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo3_data[14].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo3_data[15].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo3_data[16].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo3_data[17].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo3_data[18].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo3_data[19].supply,
		},
	},
	{
		{
			.supply = axp81x_regu_data.axp_ldo4_data[0].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo4_data[1].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo4_data[2].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo4_data[3].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo4_data[4].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo4_data[5].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo4_data[6].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo4_data[7].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo4_data[8].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo4_data[9].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo4_data[10].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo4_data[11].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo4_data[12].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo4_data[13].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo4_data[14].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo4_data[15].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo4_data[16].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo4_data[17].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo4_data[18].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo4_data[19].supply,
		},
	},
	{
		{
			.supply = axp81x_regu_data.axp_ldo5_data[0].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo5_data[1].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo5_data[2].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo5_data[3].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo5_data[4].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo5_data[5].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo5_data[6].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo5_data[7].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo5_data[8].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo5_data[9].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo5_data[10].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo5_data[11].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo5_data[12].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo5_data[13].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo5_data[14].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo5_data[15].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo5_data[16].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo5_data[17].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo5_data[18].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo5_data[19].supply,
		},
	},
	{
		{
			.supply = axp81x_regu_data.axp_ldo6_data[0].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo6_data[1].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo6_data[2].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo6_data[3].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo6_data[4].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo6_data[5].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo6_data[6].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo6_data[7].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo6_data[8].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo6_data[9].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo6_data[10].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo6_data[11].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo6_data[12].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo6_data[13].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo6_data[14].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo6_data[15].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo6_data[16].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo6_data[17].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo6_data[18].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo6_data[19].supply,
		},
	},
	{
		{
			.supply = axp81x_regu_data.axp_ldo7_data[0].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo7_data[1].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo7_data[2].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo7_data[3].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo7_data[4].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo7_data[5].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo7_data[6].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo7_data[7].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo7_data[8].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo7_data[9].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo7_data[10].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo7_data[11].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo7_data[12].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo7_data[13].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo7_data[14].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo7_data[15].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo7_data[16].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo7_data[17].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo7_data[18].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo7_data[19].supply,
		},
	},
	{
		{
			.supply = axp81x_regu_data.axp_ldo8_data[0].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo8_data[1].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo8_data[2].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo8_data[3].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo8_data[4].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo8_data[5].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo8_data[6].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo8_data[7].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo8_data[8].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo8_data[9].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo8_data[10].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo8_data[11].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo8_data[12].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo8_data[13].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo8_data[14].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo8_data[15].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo8_data[16].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo8_data[17].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo8_data[18].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo8_data[19].supply,
		},
	},
	{
		{
			.supply = axp81x_regu_data.axp_ldo9_data[0].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo9_data[1].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo9_data[2].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo9_data[3].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo9_data[4].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo9_data[5].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo9_data[6].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo9_data[7].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo9_data[8].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo9_data[9].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo9_data[10].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo9_data[11].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo9_data[12].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo9_data[13].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo9_data[14].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo9_data[15].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo9_data[16].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo9_data[17].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo9_data[18].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo9_data[19].supply,
		},
	},
	{
		{
			.supply = axp81x_regu_data.axp_ldo10_data[0].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo10_data[1].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo10_data[2].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo10_data[3].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo10_data[4].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo10_data[5].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo10_data[6].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo10_data[7].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo10_data[8].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo10_data[9].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo10_data[10].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo10_data[11].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo10_data[12].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo10_data[13].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo10_data[14].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo10_data[15].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo10_data[16].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo10_data[17].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo10_data[18].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo10_data[19].supply,
		},
	},
	{
		{
			.supply = axp81x_regu_data.axp_ldo11_data[0].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo11_data[1].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo11_data[2].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo11_data[3].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo11_data[4].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo11_data[5].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo11_data[6].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo11_data[7].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo11_data[8].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo11_data[9].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo11_data[10].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo11_data[11].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo11_data[12].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo11_data[13].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo11_data[14].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo11_data[15].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo11_data[16].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo11_data[17].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo11_data[18].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo11_data[19].supply,
		},
	},
	{
		{
			.supply = axp81x_regu_data.axp_ldo12_data[0].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo12_data[1].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo12_data[2].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo12_data[3].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo12_data[4].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo12_data[5].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo12_data[6].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo12_data[7].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo12_data[8].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo12_data[9].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo12_data[10].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo12_data[11].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo12_data[12].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo12_data[13].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo12_data[14].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo12_data[15].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo12_data[16].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo12_data[17].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo12_data[18].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo12_data[19].supply,
		},
	},
	{
		{
			.supply = axp81x_regu_data.axp_ldo13_data[0].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo13_data[1].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo13_data[2].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo13_data[3].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo13_data[4].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo13_data[5].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo13_data[6].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo13_data[7].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo13_data[8].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo13_data[9].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo13_data[10].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo13_data[11].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo13_data[12].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo13_data[13].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo13_data[14].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo13_data[15].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo13_data[16].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo13_data[17].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo13_data[18].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo13_data[19].supply,
		},
	},
	{
		{
			.supply = axp81x_regu_data.axp_ldo14_data[0].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo14_data[1].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo14_data[2].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo14_data[3].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo14_data[4].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo14_data[5].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo14_data[6].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo14_data[7].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo14_data[8].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo14_data[9].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo14_data[10].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo14_data[11].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo14_data[12].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo14_data[13].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo14_data[14].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo14_data[15].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo14_data[16].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo14_data[17].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo14_data[18].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo14_data[19].supply,
		},
	},
	{
		{
			.supply = axp81x_regu_data.axp_ldo15_data[0].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo15_data[1].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo15_data[2].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo15_data[3].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo15_data[4].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo15_data[5].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo15_data[6].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo15_data[7].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo15_data[8].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo15_data[9].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo15_data[10].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo15_data[11].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo15_data[12].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo15_data[13].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo15_data[14].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo15_data[15].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo15_data[16].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo15_data[17].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo15_data[18].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo15_data[19].supply,
		},
	},
	{
		{
			.supply = axp81x_regu_data.axp_ldo16_data[0].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo16_data[1].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo16_data[2].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo16_data[3].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo16_data[4].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo16_data[5].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo16_data[6].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo16_data[7].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo16_data[8].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo16_data[9].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo16_data[10].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo16_data[11].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo16_data[12].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo16_data[13].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo16_data[14].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo16_data[15].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo16_data[16].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo16_data[17].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo16_data[18].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo16_data[19].supply,
		},
	},
	{
		{
			.supply = axp81x_regu_data.axp_ldo17_data[0].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo17_data[1].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo17_data[2].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo17_data[3].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo17_data[4].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo17_data[5].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo17_data[6].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo17_data[7].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo17_data[8].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo17_data[9].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo17_data[10].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo17_data[11].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo17_data[12].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo17_data[13].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo17_data[14].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo17_data[15].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo17_data[16].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo17_data[17].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo17_data[18].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo17_data[19].supply,
		},
	},
	{
		{
			.supply = axp81x_regu_data.axp_ldo18_data[0].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo18_data[1].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo18_data[2].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo18_data[3].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo18_data[4].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo18_data[5].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo18_data[6].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo18_data[7].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo18_data[8].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo18_data[9].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo18_data[10].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo18_data[11].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo18_data[12].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo18_data[13].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo18_data[14].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo18_data[15].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo18_data[16].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo18_data[17].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo18_data[18].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo18_data[19].supply,
		},
	},
	{
		{
			.supply = axp81x_regu_data.axp_ldo19_data[0].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo19_data[1].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo19_data[2].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo19_data[3].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo19_data[4].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo19_data[5].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo19_data[6].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo19_data[7].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo19_data[8].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo19_data[9].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo19_data[10].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo19_data[11].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo19_data[12].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo19_data[13].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo19_data[14].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo19_data[15].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo19_data[16].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo19_data[17].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo19_data[18].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo19_data[19].supply,
		},
	},
	{
		{
			.supply = axp81x_regu_data.axp_ldo20_data[0].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo20_data[1].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo20_data[2].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo20_data[3].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo20_data[4].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo20_data[5].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo20_data[6].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo20_data[7].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo20_data[8].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo20_data[9].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo20_data[10].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo20_data[11].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo20_data[12].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo20_data[13].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo20_data[14].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo20_data[15].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo20_data[16].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo20_data[17].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo20_data[18].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo20_data[19].supply,
		},
	},
	{
		{
			.supply = axp81x_regu_data.axp_ldo21_data[0].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo21_data[1].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo21_data[2].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo21_data[3].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo21_data[4].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo21_data[5].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo21_data[6].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo21_data[7].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo21_data[8].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo21_data[9].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo21_data[10].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo21_data[11].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo21_data[12].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo21_data[13].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo21_data[14].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo21_data[15].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo21_data[16].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo21_data[17].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo21_data[18].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo21_data[19].supply,
		},
	},
	{
		{
			.supply = axp81x_regu_data.axp_ldo22_data[0].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo22_data[1].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo22_data[2].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo22_data[3].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo22_data[4].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo22_data[5].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo22_data[6].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo22_data[7].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo22_data[8].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo22_data[9].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo22_data[10].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo22_data[11].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo22_data[12].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo22_data[13].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo22_data[14].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo22_data[15].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo22_data[16].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo22_data[17].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo22_data[18].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo22_data[19].supply,
		},
	},
	{
		{
			.supply = axp81x_regu_data.axp_ldo23_data[0].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo23_data[1].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo23_data[2].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo23_data[3].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo23_data[4].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo23_data[5].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo23_data[6].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo23_data[7].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo23_data[8].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo23_data[9].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo23_data[10].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo23_data[11].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo23_data[12].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo23_data[13].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo23_data[14].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo23_data[15].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo23_data[16].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo23_data[17].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo23_data[18].supply,
		},
		{
			.supply = axp81x_regu_data.axp_ldo23_data[19].supply,
		},
	},
};

#define AXP81X_LDO(_id, min, max, step1, vreg, shift, nbits, ereg, ebit, switch_vol, step2,new_level, mode_addr, freq_addr)	\
	 AXP_LDO(AXP81X, _id, min, max, step1, vreg, shift, nbits, ereg, ebit, switch_vol, step2, new_level, mode_addr, freq_addr)
 
#define AXP81X_DCDC(_id, min, max, step1, vreg, shift, nbits, ereg, ebit, switch_vol, step2, new_level, mode_addr, freq_addr)	\
	 AXP_DCDC(AXP81X, _id, min, max, step1, vreg, shift, nbits, ereg, ebit, switch_vol, step2, new_level, mode_addr, freq_addr)
 
#define AXP81X_SW(_id, min, max, step1, vreg, shift, nbits, ereg, ebit, switch_vol, step2, new_level, mode_addr, freq_addr)	\
	AXP_SW(AXP81X, _id, min, max, step1, vreg, shift, nbits, ereg, ebit, switch_vol, step2, new_level, mode_addr, freq_addr)

static struct axp_regulator_info axp81x_regulator_info[] = {
	AXP81X_DCDC(1,	 1600,	 3400,	 100,	 DCDC1,  0,	 5,	 DCDC1EN,0, 0, 0, 0, AXP81X_DCDC_MODESET, AXP81X_DCDC_FREQSET),
	AXP81X_DCDC(2,	 500,	 1300,	 10,	 DCDC2,  0,	 7,	 DCDC2EN,1, 1200, 20, 0, AXP81X_DCDC_MODESET, AXP81X_DCDC_FREQSET),
	AXP81X_DCDC(3,	 500,	 1300,	 10,	 DCDC3,  0,	 7,	 DCDC3EN,2, 1200, 20, 0, AXP81X_DCDC_MODESET, AXP81X_DCDC_FREQSET),
	AXP81X_DCDC(4,	 500,	 1300,	 10,	 DCDC4,  0,	 7,	 DCDC4EN,3, 1200, 20, 0, AXP81X_DCDC_MODESET, AXP81X_DCDC_FREQSET),
	AXP81X_DCDC(5,	 800,	 1840,	 10,	 DCDC5,  0,	 7,	 DCDC5EN,4, 1120, 20, 0, AXP81X_DCDC_MODESET, AXP81X_DCDC_FREQSET),
	AXP81X_DCDC(6,	 600,	 1520,	 10,	 DCDC6,  0,	 7,	 DCDC4EN,5, 1100, 20, 0, AXP81X_DCDC_MODESET, AXP81X_DCDC_FREQSET),
	AXP81X_DCDC(7,	 600,	 1520,	 10,	 DCDC7,  0,	 7,	 DCDC5EN,6, 1100, 20, 0, AXP81X_DCDC_MODESET, AXP81X_DCDC_FREQSET),
	AXP81X_LDO(1,	 3000,	 3000,	 0,	 LDO1,	 0,	 0,	 LDO1EN, 5, 0, 0, 0, 0, 0),	   //ldo1 for aldo1
	AXP81X_LDO(2,	 700,	 3300,	 100,	 LDO2,	 0,	 5,	 LDO2EN, 5, 0, 0, 0, 0, 0),	   //ldo1 for aldo1
	AXP81X_LDO(3,	 700,	 3300,	 100,	 LDO3,	 0,	 5,	 LDO3EN, 6, 0, 0, 0, 0, 0),	   //ldo2 for aldo2 
	AXP81X_LDO(4,	 700,	 3300,	 100,	 LDO4,	 0,	 5,	 LDO4EN, 7, 0, 0, 0, 0, 0),	   //ldo3 for aldo3 
	AXP81X_LDO(5,	 700,	 3300,	 100,	 LDO5,	 0,	 5,	 LDO5EN, 3, 0, 0, 0, 0, 0),	   //ldo3 for dldo1 
	AXP81X_LDO(6,	 700,	 4200,	 100,	 LDO6,	 0,	 5,	 LDO6EN, 4, 3400, 200, 0, 0, 0),   //ldo5 for dldo2 
	AXP81X_LDO(7,	 700,	 3300,	 100,	 LDO7,	 0,	 5,	 LDO7EN, 5, 0, 0, 0, 0, 0),	   //ldo6 for dldo3 
	AXP81X_LDO(8,	 700,	 3300,	 100,	 LDO8,	 0,	 5,	 LDO8EN, 6, 0, 0, 0, 0, 0),	   //ldo7 for dldo4 
	AXP81X_LDO(9,	 700,	 1900,	 50,	 LDO9,	 0,	 5,	 LDO9EN, 0, 0, 0, 0, 0, 0),	   //ldo8 for eldo1 
	AXP81X_LDO(10,	 700,	 1900,	 50,	 LDO10,  0,	 5,	 LDO10EN, 1, 0, 0, 0, 0, 0),	   //ldo9 for eldo2
	AXP81X_LDO(11,	 700,	 1900,	 50,	 LDO11,  0,	 5,	 LDO11EN,2, 0, 0, 0, 0, 0),	   //ldo10 for eldo3
	AXP81X_LDO(12,	 700,	 1450,	 50,	 LDO12,  0,	 4,	 LDO12EN,2, 0, 0, 0, 0, 0),	   //ldo11 for fldo1
	AXP81X_LDO(13,	 700,	 1450,	 50,	 LDO13,  0,	 4,	 LDO13EN,3, 0, 0, 0, 0, 0),	   //ldo12 for fldo2
	AXP81X_LDO(IO0,  700,	 3300,	 100,	 LDOIO0, 0,	 5,	 LDOIO0EN,0, 0, 0, 0, 0, 0),	   //ldoio0 
	AXP81X_LDO(IO1,  700,	 3300,	 100,	 LDOIO1, 0,	 5,	 LDOIO1EN,0, 0, 0, 0, 0, 0),	   //ldoio1
	AXP81X_SW(0,	1600,	3400,	100,	 DC1SW,	0,	0,	 DC1SWEN,7, 0, 0, 0, 0, 0),//DC1SW
};

static struct axp_reg_init axp_regl_init_data[] = {
	[axp81x_vcc_dcdc1] = {
		{
			.constraints = {
				.name = "axp81x_dcdc1",
				.min_uV = 1600000,
				.max_uV = 3400000,
				.valid_ops_mask = REGULATOR_CHANGE_VOLTAGE | REGULATOR_CHANGE_STATUS,
			},
			.consumer_supplies = axp81x_supply_data.axp_ldo1_data,
		},
		.info = &axp81x_regulator_info[axp81x_vcc_dcdc1],
	},
	[axp81x_vcc_dcdc2] = {
		{
			.constraints = {
				.name = "axp81x_dcdc2",
				.min_uV = 500000,
				.max_uV = 1300000,
				.valid_ops_mask = REGULATOR_CHANGE_VOLTAGE | REGULATOR_CHANGE_STATUS,
			},
			.consumer_supplies = axp81x_supply_data.axp_ldo2_data,
		},
		.info = &axp81x_regulator_info[axp81x_vcc_dcdc2],
	},
	[axp81x_vcc_dcdc3] = {
		{
			.constraints = {
				.name = "axp81x_dcdc3",
				.min_uV = 500000,
				.max_uV = 1300000,
				.valid_ops_mask = REGULATOR_CHANGE_VOLTAGE | REGULATOR_CHANGE_STATUS,
			},
			.consumer_supplies = axp81x_supply_data.axp_ldo3_data,
		},
		.info = &axp81x_regulator_info[axp81x_vcc_dcdc3],
	},
	[axp81x_vcc_dcdc4] = {
		{
			.constraints = {
				.name = "axp81x_dcdc4",
				.min_uV = 500000,
				.max_uV = 1300000,
				.valid_ops_mask = REGULATOR_CHANGE_VOLTAGE | REGULATOR_CHANGE_STATUS,
			},
			.consumer_supplies = axp81x_supply_data.axp_ldo4_data,
		},
		.info = &axp81x_regulator_info[axp81x_vcc_dcdc4],
	},
	[axp81x_vcc_dcdc5] = {
		{
			.constraints = {
				.name = "axp81x_dcdc5",
				.min_uV = 800000,
				.max_uV = 1840000,
				.valid_ops_mask = REGULATOR_CHANGE_VOLTAGE | REGULATOR_CHANGE_STATUS,
			},
			.consumer_supplies = axp81x_supply_data.axp_ldo5_data,
		},
		.info = &axp81x_regulator_info[axp81x_vcc_dcdc5],
	},
	[axp81x_vcc_dcdc6] = {
		{
			.constraints = {
				.name = "axp81x_dcdc6",
				.min_uV = 600000,
				.max_uV = 1520000,
				.valid_ops_mask = REGULATOR_CHANGE_VOLTAGE | REGULATOR_CHANGE_STATUS,
			},
			.consumer_supplies = axp81x_supply_data.axp_ldo6_data,
		},
		.info = &axp81x_regulator_info[axp81x_vcc_dcdc6],
	},
	[axp81x_vcc_dcdc7] = {
		{
			.constraints = {
				.name = "axp81x_dcdc7",
				.min_uV = 600000,
				.max_uV = 1520000,
				.valid_ops_mask = REGULATOR_CHANGE_VOLTAGE | REGULATOR_CHANGE_STATUS,
			},
			.consumer_supplies = axp81x_supply_data.axp_ldo7_data,
		},
		.info = &axp81x_regulator_info[axp81x_vcc_dcdc7],
	},
	[axp81x_vcc_ldo1] = {
		{
			.constraints = {
				.name = "axp81x_rtc",
				.min_uV =  3000 * 1000,
				.max_uV =  3000 * 1000,
			},
			.consumer_supplies = axp81x_supply_data.axp_ldo8_data,
		},
		.info = &axp81x_regulator_info[axp81x_vcc_ldo1],
	},
	[axp81x_vcc_ldo2] = {
		{
			.constraints = {
				.name = "axp81x_aldo1",
				.min_uV = 700000,
				.max_uV = 3300000,
				.valid_ops_mask = REGULATOR_CHANGE_VOLTAGE | REGULATOR_CHANGE_STATUS,
			},
			.consumer_supplies = axp81x_supply_data.axp_ldo9_data,
		},
		.info = &axp81x_regulator_info[axp81x_vcc_ldo2],
	},
	[axp81x_vcc_ldo3] = {
		{
			.constraints = {
				.name = "axp81x_aldo2",
				.min_uV = 700000,
				.max_uV = 3300000,
				.valid_ops_mask = REGULATOR_CHANGE_VOLTAGE | REGULATOR_CHANGE_STATUS,
			},
			.consumer_supplies = axp81x_supply_data.axp_ldo10_data,
		},
		.info = &axp81x_regulator_info[axp81x_vcc_ldo3],
	},
	[axp81x_vcc_ldo4] = {
		{
			.constraints = {
				.name = "axp81x_aldo3",
				.min_uV =  700000,
				.max_uV =  3300000,
				.valid_ops_mask = REGULATOR_CHANGE_VOLTAGE | REGULATOR_CHANGE_STATUS,
			},
			.consumer_supplies = axp81x_supply_data.axp_ldo11_data,
		},
		.info = &axp81x_regulator_info[axp81x_vcc_ldo4],
	},
	[axp81x_vcc_ldo5] = {
		{
			.constraints = {
				.name = "axp81x_dldo1",
				.min_uV = 700000,
				.max_uV = 3300000,
				.valid_ops_mask = REGULATOR_CHANGE_VOLTAGE | REGULATOR_CHANGE_STATUS,
			},
			.consumer_supplies = axp81x_supply_data.axp_ldo12_data,
		},
		.info = &axp81x_regulator_info[axp81x_vcc_ldo5],
	},
	[axp81x_vcc_ldo6] = {
		{
			.constraints = {
				.name = "axp81x_dldo2",
				.min_uV = 700000,
				.max_uV = 4200000,
				.valid_ops_mask = REGULATOR_CHANGE_VOLTAGE | REGULATOR_CHANGE_STATUS,
			},
			.consumer_supplies = axp81x_supply_data.axp_ldo13_data,
		},
		.info = &axp81x_regulator_info[axp81x_vcc_ldo6],
	},
	[axp81x_vcc_ldo7] = {
		{
			.constraints = {
				.name = "axp81x_dldo3",
				.min_uV = 700000,
				.max_uV = 3300000,
				.valid_ops_mask = REGULATOR_CHANGE_VOLTAGE | REGULATOR_CHANGE_STATUS,
			},
			.consumer_supplies = axp81x_supply_data.axp_ldo14_data,
		},
		.info = &axp81x_regulator_info[axp81x_vcc_ldo7],
	},
	[axp81x_vcc_ldo8] = {
		{
			.constraints = {
				.name = "axp81x_dldo4",
				.min_uV =  700000,
				.max_uV =  3300000,
				.valid_ops_mask = REGULATOR_CHANGE_VOLTAGE | REGULATOR_CHANGE_STATUS,
			},
			.consumer_supplies = axp81x_supply_data.axp_ldo15_data,
		},
		.info = &axp81x_regulator_info[axp81x_vcc_ldo8],
	},
	[axp81x_vcc_ldo9] = {
		{
			.supply_regulator = "axp81x_dcdc1",
			.constraints = {
				.name = "axp81x_eldo1",
				.min_uV = 700000,
				.max_uV = 1900000,
				.valid_ops_mask = REGULATOR_CHANGE_VOLTAGE | REGULATOR_CHANGE_STATUS,
			},
			.consumer_supplies = axp81x_supply_data.axp_ldo16_data,
		},
		.info = &axp81x_regulator_info[axp81x_vcc_ldo9],
	},
	[axp81x_vcc_ldo10] = {
		{
			.supply_regulator = "axp81x_dcdc1",
			.constraints = {
				.name = "axp81x_eldo2",
				.min_uV = 700000,
				.max_uV = 1900000,
				.valid_ops_mask = REGULATOR_CHANGE_VOLTAGE | REGULATOR_CHANGE_STATUS,
			},
			.consumer_supplies = axp81x_supply_data.axp_ldo17_data,
		},
		.info = &axp81x_regulator_info[axp81x_vcc_ldo10],
	},
	[axp81x_vcc_ldo11] = {
		{
			.supply_regulator = "axp81x_dcdc1",
			.constraints = {
				.name = "axp81x_eldo3",
				.min_uV = 700000,
				.max_uV = 1900000,
				.valid_ops_mask = REGULATOR_CHANGE_VOLTAGE | REGULATOR_CHANGE_STATUS,
			},
			.consumer_supplies = axp81x_supply_data.axp_ldo18_data,
		},
		.info = &axp81x_regulator_info[axp81x_vcc_ldo11],
	},
	[axp81x_vcc_ldo12] = {
		{
			.constraints = {
				.name = "axp81x_fldo1",
				.min_uV = 700000,
				.max_uV = 1450000,
				.valid_ops_mask = REGULATOR_CHANGE_VOLTAGE | REGULATOR_CHANGE_STATUS,
			},
			.consumer_supplies = axp81x_supply_data.axp_ldo19_data,
		},
		.info = &axp81x_regulator_info[axp81x_vcc_ldo12],
	},
	[axp81x_vcc_ldo13] = {
		{
			.constraints = {
				.name = "axp81x_fldo2",
				.min_uV = 700000,
				.max_uV = 1450000,
				.valid_ops_mask = REGULATOR_CHANGE_VOLTAGE | REGULATOR_CHANGE_STATUS,
			},
			.consumer_supplies = axp81x_supply_data.axp_ldo20_data,
		},
		.info = &axp81x_regulator_info[axp81x_vcc_ldo13],
	},
	[axp81x_vcc_ldoio0] = {
		{
			.constraints = {
				.name = "axp81x_ldoio0",
				.min_uV = 700000,
				.max_uV = 3300000,
				.valid_ops_mask = REGULATOR_CHANGE_VOLTAGE | REGULATOR_CHANGE_STATUS,
			},
			.consumer_supplies = axp81x_supply_data.axp_ldo21_data,
		},
		.info = &axp81x_regulator_info[axp81x_vcc_ldoio0],
	},
	[axp81x_vcc_ldoio1] = {
		{
			.constraints = {
				.name = "axp81x_ldoio1",
				.min_uV = 700000,
				.max_uV = 3300000,
				.valid_ops_mask = REGULATOR_CHANGE_VOLTAGE | REGULATOR_CHANGE_STATUS,
			},
			.consumer_supplies = axp81x_supply_data.axp_ldo22_data,
		},
		.info = &axp81x_regulator_info[axp81x_vcc_ldoio1],
	},
	[axp81x_vcc_dc1sw] = {
		{
			.constraints = {
				.name = "axp81x_dc1sw",
				.min_uV = 1600,
				.max_uV = 3400000,
				.valid_ops_mask = REGULATOR_CHANGE_STATUS,
			},
			.consumer_supplies = axp81x_supply_data.axp_ldo23_data,
		},
		.info = &axp81x_regulator_info[axp81x_vcc_dc1sw],
	},
};

static struct axp_funcdev_info axp_regldevs[23] = {
	{
		.name = "axp-regulator",
		.id = AXP81X_ID_DCDC1,
		.platform_data = &axp_regl_init_data[axp81x_vcc_dcdc1],
	}, {
		.name = "axp-regulator",
		.id = AXP81X_ID_DCDC2,
		.platform_data = &axp_regl_init_data[axp81x_vcc_dcdc2],
	}, {
		.name = "axp-regulator",
		.id = AXP81X_ID_DCDC3,
		.platform_data = &axp_regl_init_data[axp81x_vcc_dcdc3],
	}, {
		.name = "axp-regulator",
		.id = AXP81X_ID_DCDC4,
		.platform_data = &axp_regl_init_data[axp81x_vcc_dcdc4],
	}, {
		.name = "axp-regulator",
		.id = AXP81X_ID_DCDC5,
		.platform_data = &axp_regl_init_data[axp81x_vcc_dcdc5],
	}, {
		.name = "axp-regulator",
		.id = AXP81X_ID_DCDC6,
		.platform_data = &axp_regl_init_data[axp81x_vcc_dcdc6],
	}, {
		.name = "axp-regulator",
		.id = AXP81X_ID_DCDC7,
		.platform_data = &axp_regl_init_data[axp81x_vcc_dcdc7],
	}, {
		.name = "axp-regulator",
		.id = AXP81X_ID_LDO1,
		.platform_data = &axp_regl_init_data[axp81x_vcc_ldo1],
	}, {
		.name = "axp-regulator",
		.id = AXP81X_ID_LDO2,
		.platform_data = &axp_regl_init_data[axp81x_vcc_ldo2],
	}, {
		.name = "axp-regulator",
		.id = AXP81X_ID_LDO3,
		.platform_data = &axp_regl_init_data[axp81x_vcc_ldo3],
	}, {
		.name = "axp-regulator",
		.id = AXP81X_ID_LDO4,
		.platform_data = &axp_regl_init_data[axp81x_vcc_ldo4],
	}, {
		.name = "axp-regulator",
		.id = AXP81X_ID_LDO5,
		.platform_data = &axp_regl_init_data[axp81x_vcc_ldo5],
	}, {
		.name = "axp-regulator",
		.id = AXP81X_ID_LDO6,
		.platform_data = &axp_regl_init_data[axp81x_vcc_ldo6],
	}, {
		.name = "axp-regulator",
		.id = AXP81X_ID_LDO7,
		.platform_data = &axp_regl_init_data[axp81x_vcc_ldo7],
	}, {
		.name = "axp-regulator",
		.id = AXP81X_ID_LDO8,
		.platform_data = &axp_regl_init_data[axp81x_vcc_ldo8],
	}, {
		.name = "axp-regulator",
		.id = AXP81X_ID_LDO9,
		.platform_data = &axp_regl_init_data[axp81x_vcc_ldo9],
	}, {
		.name = "axp-regulator",
		.id = AXP81X_ID_LDO10,
		.platform_data = &axp_regl_init_data[axp81x_vcc_ldo10],
	}, {
		.name = "axp-regulator",
		.id = AXP81X_ID_LDO11,
		.platform_data = &axp_regl_init_data[axp81x_vcc_ldo11],
	}, {
		.name = "axp-regulator",
		.id = AXP81X_ID_LDO12,
		.platform_data = &axp_regl_init_data[axp81x_vcc_ldo12],
	}, {
		.name = "axp-regulator",
		.id = AXP81X_ID_LDO13,
		.platform_data = &axp_regl_init_data[axp81x_vcc_ldo13],
	}, {
		.name = "axp-regulator",
		.id = AXP81X_ID_LDOIO0,
		.platform_data = &axp_regl_init_data[axp81x_vcc_ldoio0],
	}, {
		.name = "axp-regulator",
		.id = AXP81X_ID_LDOIO1,
		.platform_data = &axp_regl_init_data[axp81x_vcc_ldoio1],
	},{
		.name = "axp-regulator",
		.id = AXP81X_ID_SW0,
		.platform_data = &axp_regl_init_data[axp81x_vcc_dc1sw],
	},
};

extern int axp_regu_fetch_sysconfig_para(char * pmu_type, struct axp_regu_data *axpxx_data, struct axp_reg_init *axp_init_data);
struct axp_funcdev_info (* axp81x_regu_init(void))[23]
{
	int ret = 0;

	ret = axp_regu_fetch_sysconfig_para("pmu1_regu", &axp81x_regu_data, (struct axp_reg_init *)(&axp_regl_init_data));
	if (0 != ret)
		return NULL;

	return &axp_regldevs;
}

void axp81x_regu_exit(void)
{
	return;
}

