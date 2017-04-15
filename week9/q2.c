#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define N 3
#define LIMIT 20

int race=0;
pthread_mutex_t lock;
pthread_cond_t cond;

void *work(void *arg){
	int val, flag=1;
	int id=(int)arg;
	printf("Started thread #%d\n", id);
	val = (id==1 ? 3 : -1);
	while(1){
		pthread_mutex_lock(&lock);
		if(race==LIMIT){
			pthread_mutex_unlock(&lock);
			pthread_cond_signal(&cond);
			break;
		} else{
			race+=val;
			printf("Race=%d\n", race);
		}
		pthread_mutex_unlock(&lock);
		sleep(1);
	}
	pthread_exit(0);
}

void *check(void *arg){
	int id=(int)arg;
	pthread_mutex_lock(&lock);
	pthread_cond_wait(&cond, &lock);
	printf("Signal received! Race=%d\n", race);
	pthread_mutex_unlock(&lock);
	pthread_exit(0);
}

int main(){
	pthread_t thread[N];
	int i;
	pthread_mutex_init(&lock, NULL);
	pthread_cond_init(&cond, NULL);
	pthread_create(&thread[0], NULL, work, 1);
	pthread_create(&thread[1], NULL, work, 2);
	pthread_create(&thread[2], NULL, check, 3);
	for(i=0; i<N; ++i){
		pthread_join(thread[i], NULL);
	}
	pthread_mutex_destroy(&lock);
	pthread_cond_destroy(&cond);
	pthread_exit(0);
}