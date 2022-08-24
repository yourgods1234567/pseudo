#!/bin/bash
# pseudo had a bug that made it abort() when looking up a relative path from
# base "/", such as by openat(dirfd_of_root, "foo/bar") or when cwd is /. It
# tried to look up base+"/"+path = "//foo/bar", which is wrong.

set -e

touch f1
relative_pwd=${PWD#/}

cd /
cat "$relative_pwd/f1"

rm "$relative_pwd/f1"
