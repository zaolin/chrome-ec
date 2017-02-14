/* Copyright 2017 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/* GPIO interrupt/wake-up mapping */

#ifndef __CROS_EC_GPIO_WUI_H
#define __CROS_EC_GPIO_WUI_H

#include "common.h"

#define NPCX_WUI_GPIO_PIN(port, index) NPCX_WUI_GPIO_##port##_##index
#define WUI(tbl, grp, idx) ((struct npcx_wui) { .table = tbl, .group = grp, \
						.bit = idx })
#define WUI_INT(tbl, grp)  WUI(tbl, grp, 0)

/* MIWU0 */
/* Group A: NPCX_IRQ_MTC_WKINTAD_0 */
#define NPCX_WUI_GPIO_8_0 WUI(0, MIWU_GROUP_1, 0)
#define NPCX_WUI_GPIO_8_1 WUI(0, MIWU_GROUP_1, 1)
#define NPCX_WUI_GPIO_8_2 WUI(0, MIWU_GROUP_1, 2)
#define NPCX_WUI_GPIO_8_3 WUI(0, MIWU_GROUP_1, 3)
#define NPCX_WUI_GPIO_8_4 WUI(0, MIWU_GROUP_1, 4)
#define NPCX_WUI_GPIO_8_5 WUI(0, MIWU_GROUP_1, 5)
#define NPCX_WUI_GPIO_8_6 WUI(0, MIWU_GROUP_1, 6)
#define NPCX_WUI_GPIO_8_7 WUI(0, MIWU_GROUP_1, 7)

/* Group B: NPCX_IRQ_TWD_WKINTB_0 */
#define NPCX_WUI_GPIO_9_0 WUI(0, MIWU_GROUP_2, 0)
#define NPCX_WUI_GPIO_9_1 WUI(0, MIWU_GROUP_2, 1)
#define NPCX_WUI_GPIO_9_2 WUI(0, MIWU_GROUP_2, 2)
#define NPCX_WUI_GPIO_9_3 WUI(0, MIWU_GROUP_2, 3)
#define NPCX_WUI_GPIO_9_4 WUI(0, MIWU_GROUP_2, 4)
#define NPCX_WUI_GPIO_9_5 WUI(0, MIWU_GROUP_2, 5)

/* Group C: NPCX_IRQ_WKINTC_0 */
#define NPCX_WUI_GPIO_9_6 WUI(0, MIWU_GROUP_3, 0)
#define NPCX_WUI_GPIO_9_7 WUI(0, MIWU_GROUP_3, 1)
#define NPCX_WUI_GPIO_A_0 WUI(0, MIWU_GROUP_3, 2)
#define NPCX_WUI_GPIO_A_1 WUI(0, MIWU_GROUP_3, 3)
#define NPCX_WUI_GPIO_A_2 WUI(0, MIWU_GROUP_3, 4)
#define NPCX_WUI_GPIO_A_3 WUI(0, MIWU_GROUP_3, 5)
#define NPCX_WUI_GPIO_A_4 WUI(0, MIWU_GROUP_3, 6)
#define NPCX_WUI_GPIO_A_5 WUI(0, MIWU_GROUP_3, 7)

/* Group D: NPCX_IRQ_MTC_WKINTAD_0 */
#define NPCX_WUI_GPIO_A_6 WUI(0, MIWU_GROUP_4, 0)
#define NPCX_WUI_GPIO_A_7 WUI(0, MIWU_GROUP_4, 1)
#define NPCX_WUI_GPIO_B_0 WUI(0, MIWU_GROUP_4, 2)
#define NPCX_WUI_GPIO_B_1 WUI(0, MIWU_GROUP_4, 5)
#define NPCX_WUI_GPIO_B_2 WUI(0, MIWU_GROUP_4, 6)

/* Group E: NPCX_IRQ_WKINTEFGH_0 */
#define NPCX_WUI_GPIO_B_3 WUI(0, MIWU_GROUP_5, 0)
#define NPCX_WUI_GPIO_B_4 WUI(0, MIWU_GROUP_5, 1)
#define NPCX_WUI_GPIO_B_5 WUI(0, MIWU_GROUP_5, 2)
#define NPCX_WUI_GPIO_B_7 WUI(0, MIWU_GROUP_5, 4)

/* Group F: NPCX_IRQ_WKINTEFGH_0 */
#define NPCX_WUI_GPIO_C_0 WUI(0, MIWU_GROUP_6, 0)
#define NPCX_WUI_GPIO_C_1 WUI(0, MIWU_GROUP_6, 1)
#define NPCX_WUI_GPIO_C_2 WUI(0, MIWU_GROUP_6, 2)
#define NPCX_WUI_GPIO_C_3 WUI(0, MIWU_GROUP_6, 3)
#define NPCX_WUI_GPIO_C_4 WUI(0, MIWU_GROUP_6, 4)
#define NPCX_WUI_GPIO_C_5 WUI(0, MIWU_GROUP_6, 5)
#define NPCX_WUI_GPIO_C_6 WUI(0, MIWU_GROUP_6, 6)
#define NPCX_WUI_GPIO_C_7 WUI(0, MIWU_GROUP_6, 7)

/* Group G: NPCX_IRQ_WKINTEFGH_0 */
#define NPCX_WUI_GPIO_D_0 WUI(0, MIWU_GROUP_7, 0)
#define NPCX_WUI_GPIO_D_1 WUI(0, MIWU_GROUP_7, 1)
#define NPCX_WUI_GPIO_D_2 WUI(0, MIWU_GROUP_7, 2)
#define NPCX_WUI_GPIO_D_3 WUI(0, MIWU_GROUP_7, 3)

/* Group H: NPCX_IRQ_WKINTEFGH_0 */
#define NPCX_WUI_GPIO_E_7 WUI(0, MIWU_GROUP_8, 7)

/* MIWU1 */
/* Group A: NPCX_IRQ_WKINTA_1 */
#define NPCX_WUI_GPIO_0_0 WUI(1, MIWU_GROUP_1, 0)
#define NPCX_WUI_GPIO_0_1 WUI(1, MIWU_GROUP_1, 1)
#define NPCX_WUI_GPIO_0_2 WUI(1, MIWU_GROUP_1, 2)
#define NPCX_WUI_GPIO_0_3 WUI(1, MIWU_GROUP_1, 3)
#define NPCX_WUI_GPIO_0_4 WUI(1, MIWU_GROUP_1, 4)
#define NPCX_WUI_GPIO_0_5 WUI(1, MIWU_GROUP_1, 5)
#define NPCX_WUI_GPIO_0_6 WUI(1, MIWU_GROUP_1, 6)
#define NPCX_WUI_GPIO_0_7 WUI(1, MIWU_GROUP_1, 7)

/* Group B: NPCX_IRQ_WKINTB_1 */
#define NPCX_WUI_GPIO_1_0 WUI(1, MIWU_GROUP_2, 0)
#define NPCX_WUI_GPIO_1_1 WUI(1, MIWU_GROUP_2, 1)
#define NPCX_WUI_GPIO_1_3 WUI(1, MIWU_GROUP_2, 3)
#define NPCX_WUI_GPIO_1_4 WUI(1, MIWU_GROUP_2, 4)
#define NPCX_WUI_GPIO_1_5 WUI(1, MIWU_GROUP_2, 5)
#define NPCX_WUI_GPIO_1_6 WUI(1, MIWU_GROUP_2, 6)
#define NPCX_WUI_GPIO_1_7 WUI(1, MIWU_GROUP_2, 7)

/* Group C: NPCX_IRQ_KSI_WKINTC_1 */
#define NPCX_WUI_GPIO_3_1 WUI(1, MIWU_GROUP_3, 0)
#define NPCX_WUI_GPIO_3_0 WUI(1, MIWU_GROUP_3, 1)
#define NPCX_WUI_GPIO_2_7 WUI(1, MIWU_GROUP_3, 2)
#define NPCX_WUI_GPIO_2_6 WUI(1, MIWU_GROUP_3, 3)
#define NPCX_WUI_GPIO_2_5 WUI(1, MIWU_GROUP_3, 4)
#define NPCX_WUI_GPIO_2_4 WUI(1, MIWU_GROUP_3, 5)
#define NPCX_WUI_GPIO_2_3 WUI(1, MIWU_GROUP_3, 6)
#define NPCX_WUI_GPIO_2_2 WUI(1, MIWU_GROUP_3, 7)

/* Group D: NPCX_IRQ_WKINTD_1 */
#define NPCX_WUI_GPIO_2_0 WUI(1, MIWU_GROUP_4, 0)
#define NPCX_WUI_GPIO_2_1 WUI(1, MIWU_GROUP_4, 1)
#define NPCX_WUI_GPIO_3_3 WUI(1, MIWU_GROUP_4, 3)
#define NPCX_WUI_GPIO_3_4 WUI(1, MIWU_GROUP_4, 4)
#define NPCX_WUI_GPIO_3_6 WUI(1, MIWU_GROUP_4, 6)
#define NPCX_WUI_GPIO_3_7 WUI(1, MIWU_GROUP_4, 7)

/* Group E: NPCX_IRQ_WKINTE_1 */
#define NPCX_WUI_GPIO_4_0 WUI(1, MIWU_GROUP_5, 0)
#define NPCX_WUI_GPIO_4_1 WUI(1, MIWU_GROUP_5, 1)
#define NPCX_WUI_GPIO_4_2 WUI(1, MIWU_GROUP_5, 2)
#define NPCX_WUI_GPIO_4_3 WUI(1, MIWU_GROUP_5, 3)
#define NPCX_WUI_GPIO_4_4 WUI(1, MIWU_GROUP_5, 4)
#define NPCX_WUI_GPIO_4_5 WUI(1, MIWU_GROUP_5, 5)
#define NPCX_WUI_GPIO_4_6 WUI(1, MIWU_GROUP_5, 6)
#define NPCX_WUI_GPIO_4_7 WUI(1, MIWU_GROUP_5, 7)

/* Group F: NPCX_IRQ_WKINTF_1 */
#define NPCX_WUI_GPIO_5_0 WUI(1, MIWU_GROUP_6, 0)
#define NPCX_WUI_GPIO_5_1 WUI(1, MIWU_GROUP_6, 1)
#define NPCX_WUI_GPIO_5_2 WUI(1, MIWU_GROUP_6, 2)
#define NPCX_WUI_GPIO_5_3 WUI(1, MIWU_GROUP_6, 3)
#define NPCX_WUI_GPIO_5_4 WUI(1, MIWU_GROUP_6, 4)
#define NPCX_WUI_GPIO_5_5 WUI(1, MIWU_GROUP_6, 5)
#define NPCX_WUI_GPIO_5_6 WUI(1, MIWU_GROUP_6, 6)
#define NPCX_WUI_GPIO_5_7 WUI(1, MIWU_GROUP_6, 7)

/* Group G: NPCX_IRQ_WKINTG_1 */
#define NPCX_WUI_GPIO_6_0 WUI(1, MIWU_GROUP_7, 0)
#define NPCX_WUI_GPIO_6_1 WUI(1, MIWU_GROUP_7, 1)
#define NPCX_WUI_GPIO_6_2 WUI(1, MIWU_GROUP_7, 2)
#define NPCX_WUI_GPIO_6_3 WUI(1, MIWU_GROUP_7, 3)
#define NPCX_WUI_GPIO_6_4 WUI(1, MIWU_GROUP_7, 4)
#define NPCX_WUI_GPIO_6_5 WUI(1, MIWU_GROUP_7, 5)
#define NPCX_WUI_GPIO_6_6 WUI(1, MIWU_GROUP_7, 6)
#define NPCX_WUI_GPIO_7_1 WUI(1, MIWU_GROUP_7, 7)

/* Group H: NPCX_IRQ_WKINTH_1 */
#define NPCX_WUI_GPIO_7_0 WUI(1, MIWU_GROUP_8, 0)
#define NPCX_WUI_GPIO_6_7 WUI(1, MIWU_GROUP_8, 1)
#define NPCX_WUI_GPIO_7_2 WUI(1, MIWU_GROUP_8, 2)
#define NPCX_WUI_GPIO_7_3 WUI(1, MIWU_GROUP_8, 3)
#define NPCX_WUI_GPIO_7_4 WUI(1, MIWU_GROUP_8, 4)
#define NPCX_WUI_GPIO_7_5 WUI(1, MIWU_GROUP_8, 5)
#define NPCX_WUI_GPIO_7_6 WUI(1, MIWU_GROUP_8, 6)

#endif /* __CROS_EC_GPIO_WUI_H */