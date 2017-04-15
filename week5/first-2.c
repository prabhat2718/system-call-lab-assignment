#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#define FIFO_NAME1 "fifo1"
#define FIFO_NAME2 "fifo2"

int main(){
	char s[300],data[3000];
	int num,fd;
	printf("Need a writer...\n");
	fd=open(FIFO_NAME1,O_RDONLY);
	printf("Got a writer...\n");
	num=read(fd,s,300);
	printf("%d bytes read: %s\n",num,s);
	close(fd);
	int fd2=open(s,O_RDONLY,0666);
	num=read(fd2,data,3000);
	mknod(FIFO_NAME2,S_IFIFO|0666,0);
	printf("Need a reader...\n");
	fd=open(FIFO_NAME2,O_WRONLY);
	printf("Got a reader...\n");
	num=write(fd,data,strlen(data));
	printf("%d bytes written\n",num);
	close(fd);
	unlink(FIFO_NAME2);
	return 0;
}	
