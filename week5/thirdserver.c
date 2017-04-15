//Prabhat Singh
//20154018
//Assignment_5 Ques_3
//Echo service between multiple clients and server

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_NAME "myfile"
#define FIFO_NAME2 "myfile2"
#define FIFO_NAME3 "myfile3"

int main(void)
{
    char s[300];
    int num, fd,fd2,fd3;

    mknod(FIFO_NAME, S_IFIFO | 0666, 0);
    mknod(FIFO_NAME2, S_IFIFO | 0666, 0);
    mknod(FIFO_NAME3, S_IFIFO | 0666, 0);

    printf("waiting for client...\n");
    fd = open(FIFO_NAME, O_RDONLY);
    fd2 = open(FIFO_NAME2, O_WRONLY);
    fd3 = open(FIFO_NAME3, O_WRONLY);
    printf("got a client\n");
	do {
        if ((num = read(fd, s, 300)) == -1)
            perror("read");
        else {
            s[num] = '\0';
            printf("tick: read %d bytes: \"%s\"\n", num, s+1);
        }
        if(s[0]=='1')
        {
		    if ((num = write(fd2, s+1, strlen(s)-1)) == -1)
		        perror("write");
		    else
		        printf("speak: wrote %d bytes\n", num);
        }
        else if(s[0]=='2')
        {
		    if ((num = write(fd3, s+1, strlen(s)-1)) == -1)
		        perror("write");
		    else
		        printf("speak: wrote %d bytes\n", num);
        }
    } while (num > 0);
    close(fd);
    close(fd2);
    return 0;
}
