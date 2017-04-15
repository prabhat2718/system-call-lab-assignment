#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int bal=1000000;
pthread_mutex_t lock;

void *withdraw(void *arg){
	int val=-600000;
	pthread_mutex_lock(&lock);
	bal+=val;
	pthread_mutex_unlock(&lock);
}

void *deposit(void *arg){
	int val=500000;
	pthread_mutex_lock(&lock);
	bal+=val;
	pthread_mutex_unlock(&lock);
}

int main(){
	pthread_t thread_w, thread_d;
	pthread_mutex_init(&lock, NULL);
	
	pthread_create(&thread_w, NULL, withdraw, NULL);
	pthread_create(&thread_d, NULL, deposit, NULL);

	pthread_join(thread_w, NULL);
	pthread_join(thread_d, NULL);
	
	pthread_mutex_destroy(&lock);
	printf("Final Bal: %d\n", bal);
	pthread_exit(0);
}