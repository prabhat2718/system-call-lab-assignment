//Prabhat Singh
//20154018
//Assignment_5 Ques_3
//Echo service between multiple clients and server : CLIENT 2

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_NAME "myfile"
#define FIFO_NAME3 "myfile3"

int main(void)
{
    char s[300],s1[301];
    int num, fd,fd2;

    mknod(FIFO_NAME, S_IFIFO | 0666, 0);
    mknod(FIFO_NAME3, S_IFIFO | 0666, 0);

    printf("waiting for server...\n");
    fd = open(FIFO_NAME, O_WRONLY);
    fd2 = open(FIFO_NAME3, O_RDONLY);
    printf("connection established--\n");
    while (gets(s), !feof(stdin)) {
    	strcpy(s1,"2\0");
    	strcat(s1,s);
        if ((num = write(fd, s1, strlen(s1))) == -1)
            perror("write");
        else
            printf("speak: wrote %d bytes\n", num);
        if ((num = read(fd2, s, 300)) == -1)
            perror("read");
        else {
            s[num] = '\0';
            printf("tick: read %d bytes: \"%s\"\n", num, s);
        }
    }
    close(fd);
    close(fd2);
    return 0;
}
