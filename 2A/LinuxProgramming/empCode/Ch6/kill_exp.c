#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

pid_t pid;
int main (int argc, char **argv)
{
	int i, status;
	void death_handler(int sig);
	
	struct sigaction act;
	act.sa_handler=death_handler;		//set handler
	sigaction(SIGCHLD, &act, NULL);		//handler for SIGCHLD
	sigaction(SIGALRM, &act, NULL);		//handler for SIGALRM
	
	switch (pid=fork())					//fork a process
	{
		case -1: 
			fprintf(stderr, "Fork fail\n"); break;
		case 0: 						//child process
			execvp(argv[1], &argv[1]); perror("exec"); break;
		default: 						//parent process
			alarm(5); pause(); fprintf(stderr, "Parent dies.\n");				
	}
	return 0;
}

void death_handler(int sig)
{
	int status;
	switch (sig)
	{
		case SIGCHLD: 
			waitpid(-1, &status, 0);
			fprintf(stderr,"Child dies. Exit status: %d.\n",WEXITSTATUS(status));break;
		case SIGALRM: 
			if (kill(pid, SIGTERM)==0)			//send SIGTERM to child process
				fprintf(stderr, "Time out. Child killed.\n");				
	}
}
