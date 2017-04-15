/*
 * Prabhat Singh
 * 20154018
 * 1/2/17
 * Ques 3
 */
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <wait.h>

int status;
void fun(int sig){
	if(sig == SIGCHLD){
		printf("SIGCHLD recieved: status = %d\n", WEXITSTATUS(status));
	}
}

int main(){
	int pid = fork();
	if(pid < 0){
		printf("Fork error!\n");
	}
	else if(pid == 0){
		printf("Child process %d\n", getpid());
		printf("Child process exited\n");
		exit(23);
	}
	else{
		(void) signal(SIGCHLD, fun);
		printf("Parent process %d\n", getpid());
		wait(&status);
		printf("Parent process exited\n");
	}
	return 0;
}
