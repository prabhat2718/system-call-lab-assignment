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

int main(){
	int pid,status,fd[2];
	pipe(fd);
	switch(pid=fork()){
		case -1:
			printf("fork error!\n");
			break;
		case 0:
			close(fd[0]);	//read close for child
			close(1);	//close stdout
			dup(fd[1]);	//assign 1 to fd[1]
			execl("/bin/ls","ls","-l",(char *)0);
			printf("exec error!\n");
			break;
		default:
			close(fd[1]);	//write close for parent
			close(0);	//close stdin
			dup(fd[0]);	//assign 0 to fd[0]	
			execl("/bin/sort","sort -r",(char *)0);
			printf("exec error!\n");
			break;
	}	
	return 0;
}
