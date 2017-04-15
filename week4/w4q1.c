/*
 Prabhat Singh
 20154018
 25/01/2017
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

char *msg="this is a secret message.\nanyone who reads it (except you and me) will die immediately!";
int main(){
	int pid,status,fd[2];
	char buff[100];
	pipe(fd);
	switch(pid=fork()){
		case -1:
			printf("fork error!\n");
			break;
		case 0:
			close(fd[1]);	//write close for child
			read(fd[0],buff,100);
			printf("%s\n",buff);
			break;
		default:
			close(fd[0]);	//read close for parent	
			write(fd[1],msg,strlen(msg));
			break;
	}	
	return 0;
}
