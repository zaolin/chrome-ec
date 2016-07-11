# -*- makefile -*-
# Copyright 2016 The Chromium OS Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

ifeq ($(BOARD),stm32l476g-eval)
	cts-y+=$(CTS_MODULE)/th.o
	cts-y+=common/th_common.o
else
	cts-y+=$(CTS_MODULE)/dut.o
	cts-y+=common/dut_common.o
endif