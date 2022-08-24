#!/bin/bash
#
# SPDX-License-Identifier: LGPL-2.1-only
#

mode() {
	ls -l "$1" | awk '{ print $1 }'
}

rm -f a b

# Verify normal operation...
umask 022
touch a
umask 0
touch b

case $(mode a) in
-rw-r--r--*)	;;
*)	exit 1;;
esac
case $(mode b) in
-rw-rw-rw-*)	;;
*)	exit 1;;
esac

export PSEUDO_DISABLED=1

case $(mode a) in
-rw-r--r--*)	;;
*)	exit 1;;
esac
case $(mode b) in
-rw-r--r--*)	;;
*)	exit 1;;
esac

rm a b
