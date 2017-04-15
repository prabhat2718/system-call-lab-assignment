/*
Prabhat Singh
20154018
11/01/2017
Program to show orphan process
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    int status;
    pid_t pid;
    if((pid=fork())<0){
	printf("Fork error\n");
	exit(1);
    }
    if(pid==0){
	printf("Child process started PPID=%d\n", getppid());
	sleep(5);
	printf("Child process finished PPID=%d\n", getppid());
	exit(0);
    }
    else{
	sleep(1);
	exit(0);
    }
    return 0;
}
