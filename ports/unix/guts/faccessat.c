/* 
 * Copyright (c) 2021, Linux Foundation; see
 * guts/COPYRIGHT for information.
 *
 * SPDX-License-Identifier: LGPL-2.1-only
 *
 * static int
 * wrap_fsaccessat(int dirfd, const char *path, int mode, int flags) {
 *	int rc = -1;
 */
	rc = wrap_faccessat2(dirfd, path, mode, flags);

/*	return rc;
 * }
 */
