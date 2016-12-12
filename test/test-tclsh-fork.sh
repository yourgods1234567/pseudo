#!/bin/bash

# Check that tclsh doesn't hang.  Note that the timeout is not needed to
# reproduce the hang in tclsh, it's only there to ensure that this test script
# doesn't hang in case of a failing test.
timeout 2s bash -c "echo 'open {|true} r+' | tclsh"
