/*
 * Copyright (c) 2011,2014 Wind River Systems; see
 * guts/COPYRIGHT for information.
 *
 * SPDX-License-Identifier: LGPL-2.1-only
 *
 * int mknod(const char *path, mode_t mode, dev_t dev)
 *	int rc = -1;
 */

	rc = wrap_mknodat(AT_FDCWD, path, mode, dev);

/*	return rc;
 * }
 */
