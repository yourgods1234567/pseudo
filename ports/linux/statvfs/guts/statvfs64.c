/*
 * Copyright (c) 2018 Wind River Systems; see
 * guts/COPYRIGHT for information.
 *
 * SPDX-License-Identifier: LGPL-2.1-only
 *
 * int statvfs64(const char *path, struct statvfs64 *buf)
 *	int rc = -1;
 */

	rc = real_statvfs64(path, buf);

/*	return rc;
 * }
 */
