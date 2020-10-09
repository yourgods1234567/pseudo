/* 
 * Copyright (c) 2010 Wind River Systems; see
 * guts/COPYRIGHT for information.
 *
 * SPDX-License-Identifier: LGPL-2.1-only
 *
 * static int
 * wrap_mkstemp64(char *template) {
 *	int rc = -1;
 */
	/* mkstemp64() is just like mkostemp64() with no flags */
	rc = wrap_mkostemp64(template, 0);

/*	return rc;
 * }
 */
