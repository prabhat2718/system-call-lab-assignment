/*
 * Prabhat Singh
 * 20154018
 * 1/2/17
 * Ques 4
 */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <wait.h>
#include <unistd.h>
#include <signal.h>

int status;
void fun(int sig){
	switch(sig){
		case SIGINT:
			printf("SIGINT received\n");
			break;
		case SIGHUP:
			printf("SIGHUP received\n");
			break;
		case SIGTERM:
			printf("SIGTERM received\n");
			break;
		case SIGQUIT:
			printf("SIGQUIT received\n");
			exit(1);
			break;
	}
}

int main(){
	int pid = fork();
	if(pid < 0){
		printf("Fork error!\n");
	}
	else if(pid == 0){
		(void) signal(SIGINT, fun);
		(void) signal(SIGHUP, fun);
		(void) signal(SIGTERM, fun);
		(void) signal(SIGQUIT, fun);
		printf("Child process %d\n", getpid());
		while(1){
			//printf("Child process running...\n");
		}
	}
	else{
		sleep(1);
		kill(pid, SIGINT);
		sleep(1);
		kill(pid, SIGHUP);
		sleep(1);
		kill(pid, SIGTERM);
		sleep(1);
		kill(pid, SIGQUIT);
	}
	return 0;
}
