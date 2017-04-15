#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#define FILE_NAME "new.txt"
#define FIFO_NAME1 "fifo1"
#define FIFO_NAME2 "fifo2"

int main(){
	char s[300],data[3000];
	int num,fd;
	mknod(FIFO_NAME1,S_IFIFO|0666,0);
	printf("Need a reader...\n");
	fd=open(FIFO_NAME1,O_WRONLY);
	printf("Got a reader...\n");
	num=write(fd,FILE_NAME,strlen(FILE_NAME));
	printf("%d bytes written\n",num);
	close(fd);
	unlink(FIFO_NAME1);
	printf("Need a writer...\n");
	fd=open(FIFO_NAME2,O_RDONLY);
	printf("Got a writer...\n");
	num=read(fd,data,3000);
	printf("%d bytes read: %s\n",num,data);
	return 0;
}	
