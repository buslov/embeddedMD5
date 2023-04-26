#ifndef MD5_h
#define MD5_h


/*
 * This is an OpenSSL-compatible implementation of the RSA Data Security,
 * Inc. MD5 Message-Digest Algorithm (RFC 1321).
 *
 * Written by Solar Designer <solar at openwall.com> in 2001, and placed
 * in the public domain.  There's absolutely no warranty.
 *
 * This differs from Colin Plumb's older public domain implementation in
 * that no 32-bit integer data type is required, there's no compile-time
 * endianness configuration, and the function prototypes match OpenSSL's.
 * The primary goals are portability and ease of use.
 *
 * This implementation is meant to be fast, but not as fast as possible.
 * Some known optimizations are not included to reduce source code size
 * and avoid compile-time configuration.
 */

/*
 * Updated by Scott MacVicar for arduino
 * <scott@macvicar.net>
 */

#include <stddef.h>
#include <stdint.h>

#define MD5_HASH_LEN   16


typedef uint32_t MD5_u32plus;

typedef struct {
	MD5_u32plus lo, hi;
	MD5_u32plus a, b, c, d;
	MD5_u32plus block[16];
	uint8_t buffer[64];
} MD5_CTX;


uint8_t* make_hash_str(char *arg);
uint8_t* make_hash(char *arg, size_t size);
char* make_digest(const uint8_t *hash, int len);
void MD5Init(void *ctxBuf);
void MD5Update(void *ctxBuf, const void *data, size_t size);
void MD5Final(uint8_t *result, void *ctxBuf);

#endif
