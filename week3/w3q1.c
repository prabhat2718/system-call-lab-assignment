/*
  Prabhat Singh
  20154018
  19/01/17
  read and write system calls
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE 25

char buf[BUF_SIZE];
int main(){
	int fdr,fdw,charread,charwrite;
	fdr=open("/etc/passwd",O_RDONLY);
	fdw=open("passwd.bak",O_WRONLY|O_CREAT,777);
	printf("fd srcfile=%d destfile=%d\n",fdr,fdw);
	do{
		charread=read(fdr,buf,BUF_SIZE);
		charwrite=write(fdw,buf,BUF_SIZE);
		lseek(fdr,BUF_SIZE,SEEK_CUR);
	}while(charread==BUF_SIZE);
	close(fdr);
	close(fdw);
}

