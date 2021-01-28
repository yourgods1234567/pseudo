#!/bin/bash
#
# SPDX-License-Identifier: LGPL-2.1-only
#

rm -f test-rename-fstat1 test-rename-fstat2
touch test-rename-fstat1
# Will abort if it fails
./test/test-rename-fstat
ecode=$?
rm -f test-rename-fstat1 test-rename-fstat2
exit $ecode
