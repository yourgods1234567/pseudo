#! /bin/sh

# * Create a temporary directory
# * Create some symlinks in the directory
# * Run test/test-open-symlinks, which will call open(O_CREAT|O_EXCL) on the
#   symlinks in the directory and check that errno is EEXIST.

tmpdir="$(mktemp -d -p "$PWD")"
trap "rm -rf '$tmpdir'" EXIT TERM INT

# 'a' is a symlink to a file that doesn't exist
ln -s noexist.txt "$tmpdir/a"

# 'b' is a symlink to a file that doesn't exist and where we also don't have
# write permissions to the parent directory (of the target).
ln -s /root/noexist.txt "$tmpdir/b"

./test/test-open-symlinks "$tmpdir"
