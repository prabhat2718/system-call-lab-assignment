/*
 Prabhat Singh
 20154018
 22/03/17
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <pthread.h>

void *dummy(void *arg){
	int priority = 5;
	int tid = getpid();
	printf("original priority=%d\n",getpriority(PRIO_PROCESS, tid));
	printf("set priority=%d\n",priority);
	setpriority(PRIO_PROCESS, tid, priority);
	printf("new priority=%d\n", getpriority(PRIO_PROCESS, tid));
	pthread_exit(NULL);
}

int main(){
	pthread_t newthread;
	pthread_create(&newthread, NULL, dummy, NULL);
	pthread_join(newthread, NULL);
	return 0;
}

