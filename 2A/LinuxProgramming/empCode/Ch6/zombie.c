#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	pid_t pc,pr;
	int status;
	switch (fork())
	{
		case -1: 
			printf("Fork Error!\n"); break;
		case 0:
			printf("This is child process %d\n",getpid()); exit(3);
		default:
			//wait(&status);
			sleep(10);
			//wait(&status);
			printf("This is parent process %d, its child process exit status is %d\n",getpid(),WEXITSTATUS(status));
			//sleep(20);
	}
	exit(0);
}
