/*
  Prabhat Singh
  20154018
  19/01/17
  read, write and lseek system calls
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char filesrc[50], filedest[50];
char buf[2];
int main(){
	int fdr,fdw,charread,charwrite,charseek;
	printf("enter src file\n");
	scanf(" %s", filesrc);
	printf("enter dest file\n");
	scanf(" %s", filedest);
	fdr=open(filesrc,O_RDONLY);
	fdw=open(filedest,O_WRONLY|O_CREAT,777);
	printf("fd srcfile=%d destfile=%d\n",fdr,fdw);
	charseek=lseek(fdr,0,SEEK_END);
	while(charseek>0){
		--charseek;
		lseek(fdr,charseek,SEEK_SET);
		charread=read(fdr,buf,1);
		charwrite=write(fdw,buf,1);
		printf("%s",buf);
	}
	close(fdr);
	close(fdw);
}

