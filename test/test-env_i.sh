#!/bin/bash
#
# SPDX-License-Identifier: LGPL-2.1-only
#

env -i A=A B=B C=C env | grep -q "PSEUDO_"

if [ "$?" = "0" ]
then
    #echo "Passed."
    exit 0
fi
#echo "Failed"
exit 1
