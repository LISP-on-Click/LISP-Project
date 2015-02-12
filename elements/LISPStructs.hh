#ifndef LISPSTRUCTS_H
#define LISPSTRUCTS_H

/*
 * Values for the Type field.
 */
#define LISP_H_TYPE_0 0	// Reserved
#define LISP_H_TYPE_1 1	// Map-Request
#define LISP_H_TYPE_2 2	// Map-Reply
#define LISP_H_TYPE_3 3	// Map-Register
#define LISP_H_TYPE_4 4	// Map-Notify
#define LISP_H_TYPE_8 8	// Encapsulated Control Message

/*
 *  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |Type=3 |P|            Reserved               |M| Record Count  |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 */

struct LISPMapRegisterOuterHeader {
#if CLICK_BYTE_ORDER == CLICK_LITTLE_ENDIAN
	/*
	 * The Reserved field is splitted to align the fields on 8bits.
	 */
	unsigned int Reserved_1 : 3; // max value 7
	unsigned int P : 1;
	unsigned int Type : 4;
	unsigned int Reserved_2 : 8; // max value 255
	unsigned int M : 1;
	unsigned int Reserved_3 : 7; // max value 127
	unsigned int Record_Count : 8;
#else
#error "Only little endian is supported"
#endif
} CLICK_SIZE_PACKED_ATTRIBUTE;

struct LISPMapRegister {
	struct LISPMapRegisterOuterHeader header;
	uint32_t nonce1;
	uint32_t nonce2;
} CLICK_SIZE_PACKED_ATTRIBUTE;

/*
 *  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |Type=1 |A|M|P|S|p|s|    Reserved     |   IRC   | Record Count  |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 */
struct LISPMapRequestOuterHeader {
#if CLICK_BYTE_ORDER == CLICK_LITTLE_ENDIAN
	unsigned int S : 1;
	unsigned int P : 1;
	unsigned int M : 1;
	unsigned int A : 1;
	unsigned int Type : 4;
	unsigned int Reserved_1 : 6; // max value 0x3F
	unsigned int p : 1;
	unsigned int s : 1;
	unsigned int IRC : 5;
	unsigned int Reserved_2 : 3; // max value 7
	unsigned int Record_Count : 8;
#else
#error "Only little endian is supported"
#endif
} CLICK_SIZE_PACKED_ATTRIBUTE;

struct LISPMapRequest {
	struct LISPMapRequestOuterHeader header;
	uint32_t nonce1;
	uint32_t nonce2;
} CLICK_SIZE_PACKED_ATTRIBUTE;

#endif
