#define _GNU_SOURCE

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#include "pseudo.h"

int
main(int argc, char **argv) {
	int fd;
	pseudo_profile_t totals = { .total_ops = 0 }, item;
	int count = 0;

	if (argc < 2) {
		fprintf(stderr, "usage: pseudo_profile <profiling_data>\n");
		exit(1);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0) {
		fprintf(stderr, "Can't open '%s': %s.\n",
			argv[1], strerror(errno));
		exit(1);
	}
	while (read(fd, &item, sizeof(item)) == sizeof(item)) {
		if (item.total_ops > 0) {
			++count;
			totals.processes += item.processes;
			totals.total_ops += item.total_ops;
			totals.messages += item.messages;
			totals.op_time.tv_sec += item.op_time.tv_sec;
			totals.op_time.tv_usec += item.op_time.tv_usec;
			if (totals.op_time.tv_usec >= 1000000) {
				++totals.op_time.tv_sec;
				totals.op_time.tv_usec -= 1000000;
			}
			totals.ipc_time.tv_sec += item.ipc_time.tv_sec;
			totals.ipc_time.tv_usec += item.ipc_time.tv_usec;
			if (totals.ipc_time.tv_usec >= 1000000) {
				++totals.ipc_time.tv_sec;
				totals.ipc_time.tv_usec -= 1000000;
			}
			totals.wrapper_time.tv_sec += item.wrapper_time.tv_sec;
			totals.wrapper_time.tv_usec += item.wrapper_time.tv_usec;
			if (totals.wrapper_time.tv_usec >= 1000000) {
				++totals.wrapper_time.tv_sec;
				totals.wrapper_time.tv_usec -= 1000000;
			}
		}
	}
	printf("Found data for %d PIDs, %d processes.\n",
		count, totals.processes);
	printf("%lld messages for %lld ops.\n", totals.messages, totals.total_ops);
	double otime = totals.op_time.tv_sec + (totals.op_time.tv_usec / 1000000.0);
	double itime = totals.ipc_time.tv_sec + (totals.ipc_time.tv_usec / 1000000.0);
	double wtime = totals.wrapper_time.tv_sec + (totals.wrapper_time.tv_usec / 1000000.0);
	printf("%.4f msec wrapper time, %.4f msec op time, %.4f msec IPC time.\n",
		wtime * 1000, otime * 1000, itime * 1000);

	return 0;
}
