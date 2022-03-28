#!/bin/bash
#
# Test that stat'ing absolute/relative symlinks in a chroot environment works
# SPDX-License-Identifier: LGPL-2.1-only
#

set -e

touch symlink_target
trap "rm -f symlink_target symlink" 0

# Absolute symlink
ln -s /symlink_target symlink
./test/test-chroot-symlink `pwd`
rm symlink

# Relative symlink
ln -s symlink_target symlink
./test/test-chroot-symlink `pwd`
