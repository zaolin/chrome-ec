/* Copyright 2016 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef __EC_CHIP_G_UPGRADE_FW_H
#define __EC_CHIP_G_UPGRADE_FW_H

#include <stddef.h>

#define UPGRADE_PROTOCOL_VERSION 2

/* This is the format of the header the flash update function expects. */
struct upgrade_command {
	uint32_t  block_digest;  /* first 4 bytes of sha1 of the rest of the
				  * block.
				  */
	uint32_t  block_base;    /* Offset of this block into the flash SPI. */
	/* The actual payload goes here. */
} __packed;

/*
 * This is the format of the header the host uses when sending update PDUs
 * over USB. The PDUs are 1K bytes in size, they are fragmented into USB units
 * of 64 bytes each and reassembled on the receive side before being passed to
 * the flash update function.
 *
 * The flash update function receives the PDU body starting at the cmd field
 * below, and puts its reply into the beginning of the same buffer.
 */
struct update_pdu_header {
	uint32_t block_size;    /* Total size of the block, including this
				 * field.
				 */
	struct upgrade_command cmd;
};

/*
 * Response to the message initiating the update sequence.
 *
 * When responding to the very first packet of the upgrade sequence, the
 * original USB update implementation was responding with a four byte value,
 * just as to any other block of the transfer sequence.
 *
 * It became clear that there is a need to be able to enhance the upgrade
 * protocol, while stayng backwards compatible.
 *
 * All newer protocol versions (satring with version 2) respond to the very
 * first packet with an 8 byte or larger response, where the first 4 bytes are
 * a version specific data, and the second 4 bytes - the protocol version
 * number.
 *
 * This way the host receiving of a four byte value in response to the first
 * packet is considered an indication of the target running the 'legacy'
 * protocol, version 1. Receiving of an 8 byte or longer response would
 * communicates the protocol version in the second 4 bytes.
 */
struct first_response_pdu {
	uint32_t return_value;
	uint32_t protocol_version;
};

/* TODO: Handle this in upgrade_fw.c, not usb_upgrade.c */
#define UPGRADE_DONE          0xB007AB1E

void fw_upgrade_command_handler(void *body,
				size_t cmd_size,
				size_t *response_size);

#endif  /* ! __EC_CHIP_G_UPGRADE_FW_H */
