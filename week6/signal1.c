/*
 * Prabhat Singh
 * 20154018
 * 1/2/17
 * Ques 1
 */
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

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
	(void) signal(SIGINT, fun);
	(void) signal(SIGHUP, fun);
	(void) signal(SIGTERM, fun);
	(void) signal(SIGQUIT, fun);
	while(1){
		printf("running..\n");
		sleep(1);
	}
	return 0;
}
