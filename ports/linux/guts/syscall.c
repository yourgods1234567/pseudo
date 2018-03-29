/*
 * Copyright (c) 2018 Wind River Systems; see
 * guts/COPYRIGHT for information.
 *
 * long syscall(long nr)
 *	long rc = -1;
 */

	/* we should never get here, syscall is hand-wrapped */
	rc = -1;
	errno = ENOTSUPP;

/*	return rc;
 * }
 */
