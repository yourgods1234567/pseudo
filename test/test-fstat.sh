#!/bin/bash
#
# SPDX-License-Identifier: LGPL-2.1-only
#

ln -s . symlink
trap "rm symlink" 0
./test/test-fstat
