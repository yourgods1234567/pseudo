/*
 * Copyright (c) 2016 Wind River Systems; see
 * guts/COPYRIGHT for information.
 *
 * int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
 *	int rc = -1;
 */

	rc = real_bind(sockfd, addr, addrlen);
	/* we have created a thing! we need to record it in the
	 * database.
	 */
	if (addr && addr->sa_family == AF_UNIX && rc >= 0) {
		struct sockaddr_un *addr_un = (struct sockaddr_un *) addr;
		/* Linux supports a special hackery where the name starts
		 * with a nul byte, I don't care about those
		 * probably.
		 */
		if (addr_un->sun_path[0]) {
			char *path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, addr_un->sun_path, AT_SYMLINK_NOFOLLOW);
			PSEUDO_STATBUF buf;
			base_fstat(rc, &buf);
			/* we don't really care that much whether this works, I suspect */
			pseudo_client_op(OP_MKNOD, 0, -1, -1, path, &buf);
		}
	}

/*	return rc;
 * }
 */
