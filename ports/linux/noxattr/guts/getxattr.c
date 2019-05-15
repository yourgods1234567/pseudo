/*
 * Copyright (c) 2010 Wind River Systems; see
 * guts/COPYRIGHT for information.
 *
 * SPDX-License-Identifier: LGPL-2.1-only
 *
 * ssize_t getxattr(const char *pathname, const char *name, void *value, size_t size)
 *	ssize_t rc = -1;
 */

	/* suppress warnings */
	(void) pathname;
	(void) name;
	(void) value;
	(void) size;
	errno = ENOTSUP;

/*	return rc;
 * }
 */
