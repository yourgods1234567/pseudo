/*
 * Copyright (c) 2021 Richard Purdie
 *
 * SPDX-License-Identifier: LGPL-2.1-only
 *
 * int close_range(unsigned int lowfd, unsigned int maxfd, int flags)
 *      int rc = -1;
 */

        (void) lowfd;
        (void) maxfd;
        (void) flags;
        /* for now pretend the kernel doesn't support it regardless 
           which users are supposed to be able to handle */
        errno = ENOSYS;
        rc = -1;

/*      return rc;
 * }
 */
