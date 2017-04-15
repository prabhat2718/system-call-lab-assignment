/*
	Prabhat Singh
	20154018
	09/03/17
*/

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int rv;

void handler(int signl){
	if(signl==SIGCHLD){
		printf("Child Terminated with signal SIGCHLD..........\n");
		printf("Return status of child=%d............\n",WEXITSTATUS(rv));
	}
	else if(signl==SIGINT){
		printf("Parent terminated........\n");
		exit(0);
	}
}

int main (void){
	struct sigaction sig;
	sig.sa_handler=handler;
	sig.sa_flags=0;
	pid_t pid;
	if(pid=fork()==0){
	  //child process
		printf("It is the child process...............\n");
		exit(rv);
	}
	else{
		//parent process
		sigaction(SIGCHLD,&sig,NULL);
		sigaction(SIGINT,&sig,NULL);
		printf("Parent is waiting..\n");
		wait(&rv);
		printf("Press Ctrl+C to terminate the parent.......\n");
		while(1);
	}
	return 0;
}

