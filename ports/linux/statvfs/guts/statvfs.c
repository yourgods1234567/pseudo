/*
 * Copyright (c) 2018 Wind River Systems; see
 * guts/COPYRIGHT for information.
 *
 * int statvfs(const char *path, struct statvfs *buf)
 *	int rc = -1;
 */

	rc = real_statvfs(path, buf);

/*	return rc;
 * }
 */
