/*
 * Copyright (c) 2021 Richard Purdie
 *
 * SPDX-License-Identifier: LGPL-2.1-only
 *
 * void closefrom(int fd)
 */
 	pseudo_msg_t *msg;
	/* this cleans up internal tables, and shouldn't make it to the server. Avoids pseudo's internal fds */
	msg = pseudo_client_op(OP_CLOSEFROM, 0, fd, -1, 0, 0);
	/* fds between fd and msg->fd are closed within the above function avoiding pseudo's own fds */
	real_closefrom(msg->fd);

/*      return;
 * }
 */
