/*
 * Copyright (c) 2008,2011 Wind River Systems; see
 * guts/COPYRIGHT for information.
 *
 * SPDX-License-Identifier: LGPL-2.1-only
 *
 * int lchown(const char *path, uid_t owner, gid_t group)
 *	int rc = -1;
 */

	rc = wrap_chown(path, owner, group);

/*	return rc;
 * }
 */
