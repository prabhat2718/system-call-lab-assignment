/*
Prabhat Singh
20154018
11/01/2017
Program of fork, wait, print exit status of child
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    int status, pid;
    if((pid=fork())<0){
	printf("Fork error\n");
	exit(1);
    }
    if(pid==0){
	printf("Child process\n");
	exit(1);
    }
    else{
	wait(&status);
	if(WIFSIGNALED(status)){
		printf("Child terminated due to unhandled signal\n");
	}
	else if(WIFEXITED(status)){
		printf("Exit status of child=%d\n", WEXITSTATUS(status));
	}
	else{
		printf("Exit error\n");
	}
    }
    return 0;
}
