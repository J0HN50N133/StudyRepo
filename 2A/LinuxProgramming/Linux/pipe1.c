#include<stdio.h>
#include<unistd.h>
#include"quit.h"

int main()
{
	int n,fd[2];
	char buf[100];
	
	if (pipe(fd)<0)
		quit("pipe",1);
	
	switch (fork())
	{
		case -1: 
			quit("fork fail",2); break;
		case 0: 
			close(fd[1]);
			n=read(fd[0],buf,100);
			write(STDOUT_FILENO,buf,n);
			break;
		default: 
			close(fd[0]);
			write(fd[1],"Parent writing to pipe\n",23);
	}
	return 0;
}
