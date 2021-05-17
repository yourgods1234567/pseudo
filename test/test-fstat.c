/*
 * Test that stat'ing a file descriptor of a symlink does not dereference the symlink
 * SPDX-License-Identifier: LGPL-2.1-only
 *
 */
#define _GNU_SOURCE

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>

int main(void) {
    struct stat buf;
    int fd = open("symlink", O_NOFOLLOW | O_PATH);
    if (fd == -1) {
        perror("open symlink");
        return 1;
    }
    if (fstatat(fd, "", &buf, AT_EMPTY_PATH) == -1) {
        perror("stat symlink");
        return 1;
    }
    if (S_ISLNK(buf.st_mode) != 1) {
        fprintf(stderr, "path is not a symlink\n");
        return 1;
    }
    return 0;
}
