/* fcntl-linux.h doesn't define F_GETPIPE_SZ and F_SETPIPE_SZ without
 * this */
#define _GNU_SOURCE

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>

int test_pipe_sz()
{
#if defined(F_GETPIPE_SZ) && defined(F_SETPIPE_SZ)
	int pipefd[2];

	if (pipe(pipefd) < 0) {
		perror("pipe");
		return 1;
	}

	const int orig_size = fcntl(pipefd[0], F_GETPIPE_SZ);
	if (orig_size < 0) {
		perror("F_GETPIPE_SZ");
		return 1;
	}

	const int new_size = orig_size * 2;

	if (fcntl(pipefd[0], F_SETPIPE_SZ, new_size) < 0) {
		perror("F_SETPIPE_SZ");
		return 1;
	}

	const int final_size = fcntl(pipefd[0], F_GETPIPE_SZ);
	if (final_size < 0) {
		perror("Second F_GETPIPE_SZ");
		return 1;
	}

	if (final_size < new_size) {
		fprintf(stderr, "Unexpected final pipe size: %d\n", final_size);
		return 1;
	}
#else
	printf("Host too old for F_GETPIPE_SZ and F_SETPIPE_SZ tests\n");
#endif
	return 0;
}

int main()
{
	int result = 0;
	result += test_pipe_sz();
	return result;
}
