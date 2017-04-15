/*
 Prabhat Singh
 20154018 
 04/01/2017
 Print tree using fork system call
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>   

int main(){
    pid_t a=fork();
    if(a>0){
    	wait(NULL);
    }
	pid_t b=fork();
	if(b>0){
    	wait(NULL);
    }
	pid_t c=fork();
	if(c>0){
    	wait(NULL);
    }
    printf("Pid=%d Ppid=%d\n",getpid(),getppid());
    return 0;
}