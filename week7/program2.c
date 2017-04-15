/*
	Prabhat Singh
	20154018
	09/03/17
*/

#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

sigset_t set;
void handler(int sig){
	switch(sig){
		case SIGINT :
			printf(" SIGINT Signal generated.......\n");
			sleep(10);
			printf("SIGINT Signal finished...............\n");
			break;
		case SIGHUP :
			printf(" SIGHUP Signal generated ............\n");
			sleep(10);
			printf("SIGHUP Signal finished...............\n");
			break;
		case SIGTERM :
			printf(" SIGTERM Signal generated ..........\n");
			sleep(10);
			printf("SIGTERM Signal finished................\n");
			break;
		case SIGQUIT :
			printf("SIGQUIT Signal generated ..............\n");
			sleep(10);
			printf("SIGQUIT Signal finished...............\n");
			exit(0);
			break;
	}
}


int main(){
	struct sigaction sig;
	sig.sa_handler=handler;
	sig.sa_flags=0;
	sigemptyset(&set);
	sigaddset(&set,SIGINT);
	sigaddset(&set,SIGHUP);
	sigaddset(&set,SIGTERM);
	sigaddset(&set,SIGQUIT);
	sig.sa_mask=set;
	pid_t pid;
	if((pid=fork())==0){
		//child process
		sigaction(SIGINT,&sig,NULL);
			sigaction(SIGHUP,&sig,NULL);
			sigaction(SIGTERM,&sig,NULL);
		sigaction(SIGQUIT,&sig,NULL);

		while(1);
	}
	else{
		//parent process
		printf("pid=%d\n",pid);
		printf("Generate signals\n");
			while(1);
	}
	return 0;
}

