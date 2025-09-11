// Copyright 2024 Ibrahim Mbaziira
// SPDX-License-Identifier: MIT

#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
		int pid;
		pid = fork();
		printf("parent: child = %d\n", pid);
		if (pid > 0){
				pid = wait((int *) 0);
				printf("child %d is done \n", pid);
		} else if (pid == 0) {
				printf("child: exiting\n");
				exit(0);
		} else {
				printf("fork error\n");
		}
}
