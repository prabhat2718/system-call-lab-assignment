/*
 Prabhat Singh
 20154018
 25/01/2017
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	int pid,status,fd[2];
	pipe(fd);
	switch(pid=fork()){
		case -1:
			printf("fork error!\n");
			break;
		case 0:
			close(fd[0]);	//read close for child
			dup2(fd[1],1);	//assign 1 to fd[1]
			execlp(argv[1],argv[1],argv[2],(char *)0);
			printf("exec error!\n");
			break;
		default:
			wait(&status);
			close(fd[1]);	//write close for parent
			dup2(fd[0],0);	//assign 0 to fd[0]	
			execlp(argv[3],argv[3],(char *)0);
			printf("exec error!\n");
			break;
	}	
	return 0;
}
