/* 
 * Copyright (c) 2021 Linux Foundation
 *
 * SPDX-License-Identifier: LGPL-2.1-only
 *
 * static int
 * wrap_lchmod(const char *path, mode_t mode) {
 */

	rc = wrap_fchmodat(AT_FDCWD, path, mode, AT_SYMLINK_NOFOLLOW);

/*	return rc;
 * }
 */
