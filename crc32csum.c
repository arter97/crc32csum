/*
 * Copyright (C) 2020 Park Ju Hyung <qkrwngud825@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, version 2 of the
 * License.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 */

#include <errno.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#ifdef __aarch64__
#include "crc32c-arm64.c"
#define crc32c crc32c_arm64
#else
#include "crc32c.c"
#define crc32c crc32c_hw
#endif

int main(int argc, char **argv)
{
	int ret = 0;
	int fd;
	unsigned char buf[4096];
	ssize_t len;
	uint32_t crc;

	// Use stdin by default
	if (!*++argv)
		*--argv = (char*)"-";

	do {
		fd = open(strcmp(*argv, "-") ? *argv : "/dev/stdin", O_RDONLY);
		if (fd < 0) {
			fprintf(stderr, "Failed to open %s: %s\n", *argv, strerror(errno));
			ret = 1;
			continue;
		}

		crc = 0;
		while (0 < (len = read(fd, buf, 4096)))
			crc = crc32c(crc, buf, len);

		printf("%x\t%s\n", crc, *argv);

		close(fd);
	} while (*++argv);

	if (ret)
		fprintf(stderr, "WARNING: failed to process some files\n");

	return ret;
}
