/*
 * Copyright (C) 2020, NVIDIA Corporation.  All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef __MACH_TEGRA_MC_UTILS_H
#define __MACH_TEGRA_MC_UTILS_H

enum dram_types {
	DRAM_TYPE_NONE,
	DRAM_TYPE_LPDDR5_16CH_ECC_1RANK,
	DRAM_TYPE_LPDDR5_16CH_ECC_2RANK,
	DRAM_TYPE_LPDDR5_8CH_ECC_1RANK,
	DRAM_TYPE_LPDDR5_8CH_ECC_2RANK,
	DRAM_TYPE_LPDDR5_4CH_ECC_1RANK,
	DRAM_TYPE_LPDDR5_4CH_ECC_2RANK,
	DRAM_TYPE_LPDDR5_16CH_1RANK,
	DRAM_TYPE_LPDDR5_16CH_2RANK,
	DRAM_TYPE_LPDDR5_8CH_1RANK,
	DRAM_TYPE_LPDDR5_8CH_2RANK,
	DRAM_TYPE_LPDDR5_4CH_1RANK,
	DRAM_TYPE_LPDDR5_4CH_2RANK,
	DRAM_TYPE_LPDDR4_16CH_ECC_1RANK,
	DRAM_TYPE_LPDDR4_16CH_ECC_2RANK,
	DRAM_TYPE_LPDDR4_8CH_ECC_1RANK,
	DRAM_TYPE_LPDDR4_8CH_ECC_2RANK,
	DRAM_TYPE_LPDDR4_4CH_ECC_1RANK,
	DRAM_TYPE_LPDDR4_4CH_ECC_2RANK,
	DRAM_TYPE_LPDDR4_16CH_1RANK,
	DRAM_TYPE_LPDDR4_16CH_2RANK,
	DRAM_TYPE_LPDDR4_8CH_1RANK,
	DRAM_TYPE_LPDDR4_8CH_2RANK,
	DRAM_TYPE_LPDDR4_4CH_1RANK,
	DRAM_TYPE_LPDDR4_4CH_2RANK,
};

void tegra_mc_utils_init(void);

/*
 * Utility API to convert the given frequency to Bandwidth.
 *
 * @freq Frequency to convert. It can be in any unit - the resulting Bandwidth
 *       will be in the same unit as passed. E.g KHz leads to KBps and Hz
 *       leads to Bps.
 *
 * Converts EMC clock frequency into theoretical BW. This
 * does not account for a realistic utilization of the EMC bus. That is the
 * various overheads (refresh, bank commands, etc) that a real system sees
 * are not computed.
 *
 * Return: Converted Bandwidth.
 */
unsigned long emc_freq_to_bw(unsigned long freq);

/*
 * Utility API to convert the given Bandwidth to frequency.
 *
 * @bw Bandwidth to convert. It can be in any unit - the resulting frequency
 *     will be in the same unit as passed. E.g KBps leads to KHz and Bps leads
 *     to Hz.
 *
 * Converts BW into theoretical EMC clock frequency.
 *
 * Return: Converted Frequency.
 */
unsigned long emc_bw_to_freq(unsigned long bw);

enum dram_types tegra_dram_types(void);

/*
 * Return Number of channels of dram.
 *
 * Return number of dram channels
 *
 * Return: dram channels.
 */
u8 get_dram_num_channels(void);

#endif
