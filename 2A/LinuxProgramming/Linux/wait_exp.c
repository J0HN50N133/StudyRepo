#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(int argc, char **argv)   
{
	int status=0;
	switch(fork())
	{
		case 0: execvp(argv[1],&argv[1]);
		default: wait(&status);
	}
	printf("Exit status of child process is %d\n", WEXITSTATUS(status));
	exit(0);
}

