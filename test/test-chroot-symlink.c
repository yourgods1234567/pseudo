/*
 * Test that stat'ing absolute/relative symlinks in a chroot environment works
 * SPDX-License-Identifier: LGPL-2.1-only
 *
 */
#define _GNU_SOURCE

#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    struct stat buf;

    if (argc != 2) {
        perror("args");
	return 2;
    }
    if (chroot(argv[1]) == -1) {
        perror("chroot");
        return 1;
    }
    if (stat("symlink", &buf) == -1) {
        perror("stat symlink");
        return 1;
    }
    return 0;
}
