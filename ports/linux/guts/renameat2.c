/*
 * Copyright (c) 2019 Peter Seebach/Seebs <seebs@seebs.net>; see
 * guts/COPYRIGHT for information.
 *
 * [Note: copyright added by code generator, may be
 * incorrect. Remove this if you fix it.]
 *
 * int renameat2(int olddirfd, const char *oldpath, int newdirfd, const char *newpath, unsigned int flags)
 *	int rc = -1;
 */

	/* for now, let's try just failing out hard, and hope things retry with a
	 * different syscall.
	 */
	errno = ENOSYS;
	rc = -1;

/*	return rc;
 * }
 */
