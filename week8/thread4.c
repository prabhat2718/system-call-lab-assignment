/*
 Prabhat Singh
 20154018
 22/03/17
*/
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <pthread.h>
#define N 500

double sqroot[N];

void *solve(void *arg){
	int n=*(int *) arg;
	int i;
	for(i=0;i<n;++i){
		sqroot[i]=sqrt(i);
	}
	pthread_exit(NULL);
}

int main(){
	int i,n=100;
	pthread_t calcthread;
	pthread_create(&calcthread, NULL, solve, (void *)&n);
	printf("Results on the way...\n");
	pthread_join(calcthread, NULL);
	for(i=0;i<n;++i){
		printf("sqrt[%d]=%lf\n", i, sqroot[i]);
	}
	return 0;
}

