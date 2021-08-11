/*
 * Test that passing NULL to a parameter marked as nonnull works correctly
 * SPDX-License-Identifier: LGPL-2.1-only
 *
 */
#define _GNU_SOURCE

#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

// Passing a null pointer is the test scenario
#pragma GCC diagnostic ignored "-Wnonnull"

int main(void) {
    if (statx(0, NULL, 0, 0, NULL) != -1) {
        return 1;
    }
    return 0;
}
