#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include"quit.h"

int count=0;

void tstp_handler(int signum)
{
	fprintf(stderr,"\nCan't stop this program\n");
}

void int_handler(int signum)
{
	if (++count==1)
		fprintf(stderr, "\nPress again\n");
	else
		quit("\nQuitting\n", 1);
}

int main()
{
	struct sigaction act1, act2, act3;
	act1.sa_handler=tstp_handler;
	act2.sa_handler=int_handler;
	act3.sa_handler=SIG_IGN;
	
	sigaction(SIGTSTP, &act1, NULL);
	sigaction(SIGINT, &act2, NULL);
	sigaction(SIGQUIT, &act3, NULL);
	
	fprintf(stderr, "Press [Ctrl+z] first, then [Ctrl+c] \n");
	while (1)
		pause();
	
	return 0;
}

