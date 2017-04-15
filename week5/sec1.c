#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#define FIFO_NAME "fifo"

int main(){
	int num,fd,fd1,status,pid;
	mknod(FIFO_NAME,S_IFIFO|0666,0);
	fd=open(FIFO_NAME,O_WRONLY);
	close(1);
	fd1=dup(fd);
	printf("write side: fd1=%d\n",fd1);
	execlp("ls","ls","-l",(char *)0);
	return 0;
}
