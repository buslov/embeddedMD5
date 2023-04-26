/*
 * test_md5.c
 *
 *  Created on: 26 апр. 2023 г.
 *      Author: user
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#if __WIN32__
#include <fcntl.h>
#include <io.h>
#endif

#include "md5.h"


#define BUFLEN 1024


int main(int argc, char * argv[]) {
	int rtn = 0;
	uint8_t buf[BUFLEN];
	size_t sizeread;
	MD5_CTX ctx;
	uint8_t hash[MD5_HASH_LEN];
	char * digest = NULL;

#if __WIN32__
	_setmode(_fileno(stdin), _O_BINARY);
#else
	freopen(NULL, "rb", stdin);
#endif

	MD5Init(&ctx);
	while (!feof(stdin)) {
		sizeread = fread(buf, 1, BUFLEN, stdin);
		if (sizeread != 0) {
			MD5Update(&ctx, buf, sizeread);
		}
	}
	MD5Final(hash, &ctx);

	digest = make_digest(hash, MD5_HASH_LEN);

	fputs(digest, stdout);

	free(digest);


	return rtn;
}
