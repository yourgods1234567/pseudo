#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>

char *path_of(int fd) {
    ssize_t len;
    char proc[PATH_MAX], real[PATH_MAX];
    snprintf(proc, sizeof(proc), "/proc/self/fd/%d", fd);
    len = readlink(proc, real, sizeof(real));
    real[len] = '\0';
    return strdup(real);
}

/*
* Test that recusing up the tree with openat(fd, "../") handles slashes
* correctly and doesn't end up opening the same directory instead of going up a
* level.
*/
int main () {
    int fd, dir_fd;
    struct stat st;
    ino_t ino;
    dev_t dev;
    char *path;

    fd = openat(AT_FDCWD, ".", O_DIRECTORY, 0);
    fstat(fd, &st);
    ino = st.st_ino;
    dev = st.st_dev;

    while (1) {
        path = path_of(fd);
        //puts(path);

        dir_fd = openat(fd, "../", O_DIRECTORY, 0);
        fstat(dir_fd, &st);
        if (st.st_ino == ino && st.st_dev == dev) {
            if (strcmp(path, "/") == 0) {
                //puts("Reached top of tree");
                return 0;
            } else {
                //puts("Recursion failed!");
                return 1;
            }
        }

        free (path);
        ino = st.st_ino;
        dev = st.st_dev;
        fd = dir_fd;
    }
    return 0;
}
