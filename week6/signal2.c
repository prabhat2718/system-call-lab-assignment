/*
 * Prabhat Singh
 * 20154018
 * 1/2/17
 * Ques 2
 */
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void fun(int sig){
	if(sig == SIGALRM){
		printf("SIGALRM detected!\n");  
	}
}

int main(){
	int i;
	signal(SIGALRM, fun);
	for(i = 0; i< 5; ++i){
		alarm(2);
		sleep(2);
	}
	return 0;
}
