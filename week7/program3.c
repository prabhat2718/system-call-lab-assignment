/*
	Prabhat Singh
	20154018
	09/03/17
*/

#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

sigset_t set,waiting_mask;
void handler(int sig){
	int c;
	switch(sig){
		case SIGINT :
			sigaddset(&set,SIGHUP);
			sigaddset(&set,SIGABRT);
			sigprocmask(SIG_BLOCK, &set, NULL);
			printf("SIGINT Signal generated ...........\n");
			sleep(10);
			sigpending (&waiting_mask);
			printf("List of blocked signals::");
			if (sigismember (&waiting_mask, SIGINT)) {
				printf("SIGINT::");
				c++;
			}
			if (sigismember (&waiting_mask, SIGHUP)) {
				printf("SIGHUP::");
				c++;
			}
			if (sigismember (&waiting_mask, SIGABRT)) {
				printf("SIGABRT");
				c++;
			}
			printf("\nNo of signals blocked=%d\n",c);
			printf("Signal SIGTERM finished\n");
			sigprocmask(SIG_UNBLOCK, &set, NULL);
			sigemptyset(&set);
			break;
		case SIGQUIT :
			sigaddset(&set,SIGHUP);
			sigaddset(&set,SIGTERM);
			sigprocmask(SIG_BLOCK, &set, NULL);
			printf("Signal SIGQUIT generated.........\n");
			sleep(10);
			printf("Signal SIGQUIT finished...........\n");
			exit(0);
			break;
	}
}

int main(){
	struct sigaction sig;
	sig.sa_handler=handler;
	sig.sa_flags=0;
	sigemptyset(&set);
	sigaction(SIGINT,&sig,NULL);
	sigaction(SIGHUP,&sig,NULL);
	sigaction(SIGTERM,&sig,NULL);
	sigaction(SIGQUIT,&sig,NULL);
	printf("pid=%d\n",getpid());
	printf("Generate Signal SIGTERM and then try to generate SIGINT SIGHUP and SIGABRT in 10 seconds\n");
	while(1);
	return 0;
}

