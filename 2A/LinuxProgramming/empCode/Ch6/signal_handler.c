#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include"quit.h"
#define BUFSIZE 100

char buf[BUFSIZE]="foo";

void alrm_handler(int signum)
{
	fprintf(stderr,"\nSignal %d received, default filename: %s\n",signum,buf);
}

int main()
{
	int n;
	struct sigaction act;
	act.sa_handler=alrm_handler;
	if (sigaction(SIGALRM, &act, NULL)==-1)
		quit("sigalrm",1);
	
	fprintf(stderr,"Enter filename: ");
	alarm(5);
	n=read(STDIN_FILENO, buf, BUFSIZE);
	if (n>0)
		fprintf(stderr,"Filename: %s\n",buf);
	
	return 0;
}
