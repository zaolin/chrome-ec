/* Copyright 2016 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 *
 * RSA 2048 with 3 exponent public key and verification.
 * Private key in rsa2048-3.pem.
 */

/* First generate a key:
 * # openssl genrsa -3 -out key.pem 2048
 * # openssl rsa -in key.pem -pubout > key.pub
 * Then dump the key:
 * # dumpRSAPublicKey -pub key.pub | xxd -i
 * That's a slightly different format, so comment out the 1st 4 bytes (length),
 * and move the next 4 to the end (n0inv).
 */
const uint8_t rsa_data[] = {
	/*  Length */
	/* 0x40, 0x00, 0x00, 0x00, */
	0x11, 0x17, 0x38, 0xfd,
	0xef, 0xa2, 0xb5, 0x2d, 0x6d, 0x76, 0xe1, 0x70, 0x7d, 0x67, 0xb1, 0x9a,
	0x18, 0x78, 0x90, 0xe2, 0xce, 0xa6, 0x81, 0xa0, 0x13, 0x37, 0xf2, 0x71,
	0xf0, 0x44, 0x96, 0xaf, 0x52, 0x53, 0xd4, 0x23, 0x51, 0x19, 0xe5, 0xb0,
	0x6d, 0x95, 0x99, 0x11, 0x88, 0x5c, 0xed, 0x52, 0x62, 0x07, 0xa6, 0x02,
	0xc6, 0xba, 0x48, 0xae, 0x78, 0xd9, 0xfb, 0x73, 0x7a, 0x33, 0xfe, 0x8b,
	0xe5, 0x38, 0xf6, 0x8b, 0xa1, 0x3f, 0x1d, 0xe1, 0xfc, 0xae, 0x19, 0xf1,
	0x80, 0x94, 0x06, 0xfc, 0x44, 0x69, 0x3c, 0xec, 0xb2, 0xf0, 0x29, 0x9a,
	0x97, 0x09, 0x81, 0x88, 0x1a, 0x56, 0x2e, 0xcb, 0xf9, 0x0b, 0x08, 0x5c,
	0xd3, 0x44, 0x6a, 0xce, 0xe2, 0xbc, 0x71, 0x03, 0x93, 0x0b, 0x80, 0x0e,
	0x12, 0x4c, 0x25, 0x61, 0x97, 0x15, 0x8a, 0x91, 0x37, 0x1e, 0x63, 0x35,
	0x83, 0xa0, 0xb8, 0xbb, 0x07, 0x80, 0x7f, 0xbf, 0x2c, 0x1e, 0xab, 0xeb,
	0xfb, 0x3d, 0x2c, 0xe7, 0xee, 0x32, 0xca, 0x7f, 0x9b, 0xe5, 0xf7, 0x04,
	0xcc, 0xd5, 0xc9, 0x99, 0x55, 0xd2, 0xdb, 0xe5, 0x27, 0x70, 0xac, 0x1a,
	0x81, 0x07, 0xff, 0x99, 0x5f, 0x34, 0x6a, 0x91, 0x5a, 0xb3, 0x3a, 0x37,
	0xef, 0x61, 0xd4, 0xab, 0xf2, 0x90, 0x98, 0x9a, 0xf7, 0x35, 0x73, 0x93,
	0x64, 0xf1, 0x27, 0x3f, 0x9a, 0x52, 0xa6, 0x91, 0x89, 0xb0, 0x5e, 0x70,
	0x4c, 0x7e, 0x9e, 0x80, 0x50, 0x2a, 0x25, 0x78, 0xea, 0x6d, 0xad, 0x96,
	0x04, 0x45, 0x92, 0xaa, 0x03, 0x6f, 0xec, 0x31, 0xbf, 0x82, 0x4b, 0x4e,
	0xb5, 0xf2, 0xc2, 0x0b, 0x88, 0x0a, 0x26, 0xac, 0x2e, 0x02, 0x08, 0x38,
	0xce, 0xbd, 0x12, 0xd0, 0x1b, 0x6a, 0x82, 0xe2, 0xe9, 0xb2, 0x9a, 0x3c,
	0x1f, 0x61, 0xa0, 0xac, 0xa6, 0x8d, 0x49, 0x60, 0xd6, 0xf5, 0x65, 0xda,
	0xde, 0x9e, 0xda, 0x20, 0x67, 0x58, 0x0f, 0xd8, 0x71, 0xd4, 0x21, 0xf5,
	0xef, 0x64, 0x91, 0x14, 0x1b, 0xc2, 0x2d, 0x8f, 0x5f, 0xa2, 0x09, 0xc4,
	0x82, 0x7f, 0x3a, 0xca, 0xef, 0x5a, 0x12, 0x20, 0x0e, 0x68, 0x36, 0xf1,
	0xe0, 0xa2, 0x03, 0x90, 0x68, 0x67, 0xdc, 0x6c, 0x44, 0x41, 0xc7, 0x49,
	0xad, 0xa3, 0x93, 0xe7, 0xa3, 0xa1, 0x88, 0xd9, 0xf6, 0x14, 0x2d, 0x8a,
	0xc2, 0x8f, 0xb9, 0x14, 0x06, 0xdc, 0x14, 0xd1, 0xe2, 0xf6, 0x04, 0x0b,
	0x24, 0x42, 0x24, 0x8a, 0x2e, 0x09, 0x02, 0xeb, 0x55, 0x62, 0x57, 0x67,
	0x34, 0xf0, 0xa4, 0x30, 0xb3, 0x06, 0xd9, 0xa3, 0x6c, 0xf3, 0x1f, 0x5f,
	0x8f, 0x36, 0x82, 0x3c, 0x12, 0x97, 0x6a, 0xff, 0x84, 0xcd, 0x98, 0x88,
	0xad, 0xc2, 0xa0, 0xcc, 0xea, 0x33, 0x7a, 0xc3, 0x7d, 0x29, 0x90, 0x1e,
	0xd0, 0x3e, 0x2e, 0x0f, 0xa1, 0xc1, 0x16, 0x46, 0x1c, 0xcd, 0xb0, 0x4e,
	0x44, 0x61, 0xa2, 0x77, 0x25, 0x40, 0xba, 0xe6, 0x89, 0xf8, 0xba, 0x5d,
	0xe0, 0x4b, 0x6d, 0x8c, 0xe4, 0xe7, 0xf0, 0x5f, 0x13, 0x25, 0x51, 0x72,
	0x3b, 0xeb, 0x32, 0xaf, 0x80, 0xde, 0xa6, 0x20, 0x63, 0x38, 0x43, 0x10,
	0xf7, 0x8e, 0xfb, 0xd3, 0x06, 0xf9, 0x51, 0x98, 0xf8, 0xc1, 0x62, 0x0d,
	0x23, 0x2b, 0x66, 0xd9, 0xe7, 0xd5, 0x03, 0xbb, 0xee, 0x36, 0xde, 0x5c,
	0xd8, 0x22, 0x7c, 0x4b, 0xf9, 0x26, 0x63, 0x96, 0x6a, 0x4c, 0x9b, 0x59,
	0xd0, 0xf2, 0xc4, 0xf8, 0x79, 0xf5, 0x43, 0x9b, 0xdf, 0x26, 0xeb, 0x2e,
	0x80, 0xe2, 0x27, 0x9e, 0xd3, 0xa5, 0x45, 0x37, 0x4c, 0xbd, 0xf9, 0xb0,
	0x23, 0xa1, 0x21, 0x4e, 0x1f, 0x6e, 0xdd, 0xac, 0xa6, 0x2c, 0x83, 0x61,
	0xdf, 0x8f, 0x9a, 0xfb, 0x55, 0x0a, 0x88, 0x0b, 0x0b, 0x34, 0xbd, 0x35,
	0x43, 0x2d, 0xe4, 0x49,
	/* n0inv */
	0x0f, 0x46, 0xe8, 0x2c
};

const struct rsa_public_key *rsa_key = (struct rsa_public_key *)rsa_data;
BUILD_ASSERT(sizeof(*rsa_key) == sizeof(rsa_data));

/* SHA-256 sum to verify:
 * # sha256sum README | sed -e 's/\(..\)/0x\1, /mg'
 */
const uint8_t hash[] = {
	0x6c, 0x5f, 0xef, 0x7f, 0x63, 0x1d, 0xb4, 0x35, 0x6c, 0xae, 0x8b, 0x2a,
	0x4e, 0xde, 0xc5, 0xeb, 0x11, 0xba, 0x1f, 0x44, 0x40, 0xb6, 0x3a, 0x52,
	0xf2, 0x70, 0xef, 0xee, 0x44, 0x4b, 0x57, 0x62
};

/* Incorrect hash to test the negative case */
const uint8_t hash_wrong[] = {
	0x61, 0x1b, 0xd2, 0x44, 0xc7, 0x18, 0xa7, 0x2d, 0x0f, 0x2d, 0x3d, 0x0f,
	0xe3, 0xb3, 0xc5, 0xe4, 0x12, 0xc2, 0x7b, 0x1e, 0x05, 0x2c, 0x6f, 0xad,
	0xc4, 0xac, 0x71, 0x55, 0xe8, 0x80, 0x5c, 0x38
};

/* Generate signature using futility:
 * # futility create key.pem
 * # futility sign --type rwsig --prikey key.vbprik2 README README.out
 * # dd skip=56 bs=1 if=README.out | xxd -i
 */
const uint8_t sig[] = {
	0xad, 0x93, 0x9d, 0x5e, 0x4b, 0x66, 0xbd, 0xaa, 0xd0, 0x31, 0x15, 0x0f,
	0x0c, 0x2c, 0x48, 0x61, 0xfc, 0x81, 0xef, 0xbf, 0x99, 0x7d, 0xc8, 0x51,
	0x78, 0x84, 0xb0, 0x7c, 0x26, 0x09, 0x5c, 0x53, 0x36, 0x8c, 0xef, 0xef,
	0x24, 0x71, 0xe8, 0xff, 0xa7, 0xac, 0x1a, 0xe3, 0xf7, 0xf3, 0x88, 0xde,
	0xc8, 0x2c, 0x13, 0x29, 0x30, 0x90, 0xf9, 0xb0, 0xbc, 0x10, 0xcc, 0x72,
	0xc7, 0xb0, 0x4c, 0x0e, 0x0c, 0x14, 0xe1, 0xca, 0x41, 0x4d, 0x3c, 0x40,
	0x8e, 0x2e, 0x45, 0x90, 0x7a, 0xb4, 0xa5, 0xd6, 0x8f, 0xf6, 0xfb, 0xef,
	0x51, 0x47, 0x60, 0x21, 0x6d, 0x6f, 0xae, 0x9b, 0xb1, 0x9b, 0x34, 0x48,
	0x21, 0x9a, 0x5e, 0x70, 0xa3, 0x52, 0xa2, 0x00, 0x11, 0x20, 0x2d, 0x2a,
	0xda, 0xc1, 0x23, 0x46, 0xbc, 0xb5, 0xa4, 0x0a, 0xec, 0x6a, 0x3a, 0xe4,
	0x96, 0x17, 0x8a, 0x69, 0xce, 0x6f, 0xb0, 0x1d, 0x24, 0xd5, 0x20, 0x03,
	0x0d, 0xe4, 0x6a, 0xf2, 0x8d, 0x19, 0x13, 0x7f, 0xd0, 0xe9, 0x51, 0xc7,
	0x9b, 0x43, 0x11, 0xb4, 0x77, 0x1c, 0xed, 0xb9, 0xf0, 0xfc, 0xc3, 0xf7,
	0x1a, 0xa0, 0x5e, 0x35, 0x2d, 0xc4, 0x35, 0x15, 0x42, 0xfa, 0x2f, 0xeb,
	0xe6, 0xc6, 0xed, 0x98, 0x42, 0x93, 0xb1, 0x26, 0x61, 0x29, 0x37, 0xee,
	0x87, 0x88, 0x7c, 0xc6, 0xa3, 0xd0, 0x5b, 0xaf, 0xb3, 0x19, 0xa1, 0x1d,
	0x5f, 0x13, 0x37, 0x58, 0x33, 0x3b, 0xa8, 0xef, 0xea, 0x17, 0x87, 0x99,
	0x43, 0xe3, 0x0a, 0x97, 0xdb, 0x8d, 0x54, 0x69, 0x33, 0x58, 0x9d, 0x2f,
	0xfc, 0x32, 0x78, 0xca, 0x3a, 0x65, 0xca, 0x8e, 0x9b, 0x94, 0x18, 0xaa,
	0xf0, 0x2b, 0x97, 0xcc, 0xa9, 0xd2, 0xd0, 0x8c, 0x73, 0xd6, 0x82, 0x99,
	0xac, 0x07, 0x74, 0x47, 0x6e, 0x4c, 0x7b, 0xf9, 0x18, 0xf6, 0x13, 0x50,
	0x9e, 0xea, 0xc7, 0x1c,
	/* Padding */
	0x00
};
