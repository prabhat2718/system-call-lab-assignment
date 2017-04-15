#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#define FIFO_NAME "fifo"
int main(){
	int num,fd,fd1,pid,status;
	mknod(FIFO_NAME,S_IFIFO|0666,0);
	fd=open(FIFO_NAME,O_RDONLY);
	close(0);
	fd1=dup(fd);
	printf("read side: fd1=%d\n",fd1);
	execlp("sort","sort -",(char *)0);
	return 0;
}	
