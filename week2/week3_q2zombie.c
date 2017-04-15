/*
Prabhat Singh
20154018
11/01/2017
Program to show zombie process
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

char *argv[]={"/bin/ps", "-el"};
int main(){
    int status;
    pid_t pid, pid2;
    if((pid=fork())<0){
	printf("Fork error\n");
	exit(1);
    }
    if(pid==0){
	exit(0);
    }
    else{
	printf("PID of Child=%d\n", pid);
	sleep(5);
	if((pid2=fork())<0){
		printf("Fork2 error\n");
	}
	if(pid2==0){
		execv(argv[0], argv);
	}
	else{
		sleep(5);
		wait(&status);
	}
    }
    return 0;
}
