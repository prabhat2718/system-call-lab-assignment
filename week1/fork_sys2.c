/*
 Prabhat Singh
 20154018 
 04/01/2017
 Print chain of 5 length
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>  

int main(){
    int n=5, i; pid_t child;
    for(i=1; i<=n; ++i){
        printf("Pid=%d Ppid=%d\n", getpid(), getppid());
        child=fork();
        if(child>0){
            wait(NULL); exit(1);
        }
    }
    return 0;
}
