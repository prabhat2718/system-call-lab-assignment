/*
 Prabhat Singh
 20154018
 22/03/17
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 10

void *PrintHello(void *threadid){
	int tid=(int)threadid;
	printf("Hello, World (thread %d)\n", tid);
	pthread_exit(NULL);
}

int main(int argc, char *argv[]){
	pthread_t threads[NUM_THREADS];
	int rc, t;
	for(t=0;t<NUM_THREADS;++t){
		rc=pthread_create(&threads[t], NULL, PrintHello, (void *) t);	
		if(rc){
			printf("Error! return code from pthread_create is %d\n", rc);
			exit(1);
		}
	}
	for(t=0;t<NUM_THREADS;++t){
		pthread_join(threads[t], NULL);
	}
	return 0;
}
