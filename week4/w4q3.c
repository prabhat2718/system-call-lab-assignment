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

int main(int argc, char *argv[]){
	int pid,status,fd[2];
	char command[100]="xterm -e 'man ";
	char msg[50];
	pipe(fd);
	switch(pid=fork()){
		case -1:
			printf("fork error!\n");
			break;
		case 0:
			close(fd[1]);	//write close for child
			read(fd[0],msg,100);
			strcat(command,msg);
			strcat(command,"'");
			printf("%s\n",command);
			system(command);
			break;
		default:
			close(fd[0]);	//read close for parent	
			write(fd[1],argv[1],strlen((const char *)argv));
			wait(&status);
			break;
	}	
	return 0;
}
