#include <stdio.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>


struct testcase {
    const char * pathname;
    int flags;
    mode_t mode;
    int expected_errno;
};

/*
* List of test cases to run. The files (given by 'pathname') are expected to be
* setup by test-open-symlinks.sh.
*/
static const struct testcase testcases[] = {
    { "a", O_WRONLY|O_CREAT|O_EXCL, 0644, EEXIST },
    { "a", O_RDWR|O_CREAT|O_EXCL, 0644, EEXIST },
    { "b", O_WRONLY|O_CREAT|O_EXCL, 0644, EEXIST },
    { "b", O_RDWR|O_CREAT|O_EXCL, 0644, EEXIST },
    { NULL }
};

static bool run_testcase(const char * progname,
                         const struct testcase * testcase);

static int try_open(const char * pathname, int flags, mode_t mode);

/*
* Given a directory (which is expected to be setup containing some files by
* test-open-symlinks.sh), loop through the test cases listed above and check
* that when calling open(pathname, flags, mode), errno is set to the expected
* value.
*/
int main(int argc, char *argv[]) {
    const char * progname = argv[0];

    if (argc != 2) {
        fprintf(stderr, "usage: %s <dir>\n", progname);
        return 1;
    }

    const char * dirname = argv[1];
    if (chdir(dirname) != 0) {
        perror(dirname);
        return 1;
    }

    bool ok = true;

    for (int i = 0; testcases[i].pathname; i++) {
        ok &= run_testcase(progname, &testcases[i]);
    }

    return ok ? 0 : 1;
}

/*
* Given a test case of (pathname, flags, mode, expected_errno), open the file
* with the given arguments and return true if the actual errno matches the
* expected one, or otherwise false.
*/
static bool run_testcase(const char * progname,
                         const struct testcase * testcase) {

    int actual_errno = try_open(testcase->pathname,
                                testcase->flags,
                                testcase->mode);

    if (actual_errno != testcase->expected_errno) {
        fprintf(stderr, "%s: open(%s, 0x%x, %o) -> %s (expected: %s)\n",
               progname, testcase->pathname, testcase->flags, testcase->mode,
               strerror(actual_errno), strerror(testcase->expected_errno));
        return false;
    }

    return true;
}

/*
* open() a file with the given flags and mode and return errno (or 0, if the
* file was successfully opened).
*/
static int try_open(const char * pathname, int flags, mode_t mode) {
    int fd = open(pathname, flags, mode);

    if (fd >= 0) {
        close(fd);
        return 0;
    }

    return errno;
}
