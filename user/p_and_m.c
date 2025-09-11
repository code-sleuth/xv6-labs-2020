// Copyright 2024 Ibrahim Mbaziira
// SPDX-License-Identifier: MIT

#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
		int pid;
		pid = fork();
		if (pid > 0){
				// Parent process: wait first, then print
				pid = wait((int *) 0);
				printf("parent: child = %d\n", pid);
				printf("child %d is done \n", pid);
		} else if (pid == 0) {
				// Child process
				printf("child: exiting\n");
				exit(0);
		} else {
				// Fork failed
				printf("fork error\n");
		}
		exit(0);
}

// Output:
// child: exiting
// parent: child = 4
// child 4 is done
