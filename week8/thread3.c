/*
 Prabhat Singh
 20154018
 22/03/17
*/
#include <stdio.h>
#include <pthread.h>
#define N 50

int n,k,m,a[N][N],b[N][N],c[N][N];
struct val{
	int row,col;
};

void *solve(void *arg){
	struct val values = *(struct val *)arg;
	int row=values.row, col=values.col;
	int i,j;
	for(i=0;i<k;++i){
		c[row][col]+=a[row][i]*b[i][col];
	}
	pthread_exit(NULL);
}

int main(){
	int i,j;
	pthread_t threads[N][N];
	struct val values;
	scanf("%d%d%d",&n,&k,&m);
	for(i=0;i<n;++i){
		for(j=0;j<k;++j){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<k;++i){
		for(j=0;j<m;++j){
			scanf("%d",&b[i][j]);
		}
	}
	for(i=0;i<n;++i){
		for(j=0;j<m;++j){
			values.row=i;
			values.col=j;
			pthread_create(&threads[i][j], NULL, solve, (void *) &values);
			pthread_join(threads[i][j], NULL);
		}
	}
	for(i=0;i<n;++i){
		for(j=0;j<m;++j){
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
	return 0;
}
