#!/bin/bash
#
# SPDX-License-Identifier: LGPL-2.1-only
#
set -e

# Verify that special bits (setuid/setgid/sticky) are preserved.
#
# Return vals:
#
#                 2 - Incorrect permissions
# All other nonzero - Unexpected command error
#                 0 - Pass

trap "rm -rf d1 d2" EXIT

mkdir d1
chmod 7777 d1
cp -Rp d1 d2
perms=`ls -od d1 d2 | cut -c 1-10 | uniq`
if [ "$perms" != drwsrwsrwt ]; then
	exit 2
fi


exit 0
