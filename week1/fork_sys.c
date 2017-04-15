/*
 Prabhat Singh
 20154018 
 04/01/2017
 Print pid, child id, owner id of parent process & pid, ppid of child process
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	pid_t pid;
	int i, res;
	pid=fork();
	switch(pid){
		case -1:
			perror("Error\n");
			break;
		case 0:
			printf("I am child. My ID=%d, My Parent ID=%d\n", getpid(), getppid());
			for(i=0; i<20; ++i)
				printf("Inside child looping %d time\n", i);
			printf("Child exiting\n");
			exit(34);
		default:
			printf("I am parent. My ID=%d, My Child ID=%d, User ID=%d\n", getpid(), pid, getuid());
			for(i=0; i<20; ++i)
				printf("Inside Parent looping %d time\n", i);
			wait(&res);
			printf("Child exited with status %d\n", WEXITSTATUS(res));
	}
	return 0;
}
