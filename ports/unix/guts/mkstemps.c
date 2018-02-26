/*
 * Copyright (c) 2018 Wind River Systems; see
 * guts/COPYRIGHT for information.
 *
 * int mkstemps(char *template, int suffixlen)
 *	int rc = -1;
 */

	/* mkstemps() is mkostemps() with no flags */
	rc = wrap_mkostemps(template, suffixlen, 0);

/*	return rc;
 * }
 */
