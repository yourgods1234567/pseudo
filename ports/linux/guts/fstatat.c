/*
 * Copyright (c) 2021 Linux Foundation; see
 * guts/COPYRIGHT for information.
 *
 * SPDX-License-Identifier: LGPL-2.1-only
 *
 * int fstatat(int dirfd, const char *path, struct stat *buf, int flags)
 *	int rc = -1;
 */

	rc = wrap___fxstatat(_STAT_VER, dirfd, path, buf, flags);

/*	return rc;
 * }
 */
