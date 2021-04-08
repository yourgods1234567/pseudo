#! /bin/sh

# Test with and without paths being ignored. The bug was with paths being ignored.

./test/test-openat

PSEUDO_IGNORE_PATHS=/ ./test/test-openat
