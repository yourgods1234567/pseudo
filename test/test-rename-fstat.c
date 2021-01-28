/*
 * SPDX-License-Identifier: LGPL-2.1-only
 *
 * Test we can rename a file whilst holding an open fd which we fstat after renaming
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    struct stat buf;
    int err;
    int fd = open("test-rename-fstat1", O_RDONLY);
    err = rename("test-rename-fstat1", "test-rename-fstat1");
    if (err)
        return err;
    return fstat(fd, &buf);
}
