/*
Prabhat Singh
20154018
11/01/2017
Program to show exec
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

char *argv[]={"/bin/ls", "-la", 0};
int main(){
    int status;
    pid_t pid;
    if((pid=fork())<0){
	    printf("Fork error\n");
	    exit(1);
    }
    if(pid==0){
	    printf("Child process started\n");
	    execv(argv[0], argv);
    }
    else{
	    wait(&status);
	    if(WIFSIGNALED(status)){
		    printf("Child terminated by unhandled signal\n");
	    }
	    if(WIFEXITED(status)){
		    printf("Exit status of child=%d\n", WEXITSTATUS(status));
	    }
	    else{
		    printf("Exit error\n");
	    }
    }
    return 0;
}
