/* 
 * Copyright (c) 2021, Linux Foundation; see
 * guts/COPYRIGHT for information.
 *
 * SPDX-License-Identifier: LGPL-2.1-only
 *
 * static int
 * wrap_fsaccessat2(int dirfd, const char *path, int mode, int flags) {
 *	int rc = -1;
 */
	PSEUDO_STATBUF buf;

#ifdef PSEUDO_NO_REAL_AT_FUNCTIONS
	if (dirfd != AT_FDCWD) {
		errno = ENOSYS;
		return -1;
	}
	if (flags & AT_SYMLINK_NOFOLLOW) {
		rc = base_lstat(path, &buf);
	} else {
		rc = base_stat(path, &buf);
	}
#else
	rc = base_fstatat(dirfd, path, &buf, flags & AT_SYMLINK_NOFOLLOW);
#endif
	if (rc == -1)
		return rc;

	/* note:  no attempt to handle the case where user isn't
	 * root.
	 */

	if (mode & X_OK) {
		if (buf.st_mode & 0111) {
			return 0;
		} else {
			errno = EACCES;
			return -1;
		}
	} else {
		return 0;
	}

/*	return rc;
 * }
 */
