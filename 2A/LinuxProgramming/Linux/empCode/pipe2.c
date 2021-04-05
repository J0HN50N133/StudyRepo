#include<stdio.h>
#include<unistd.h>
#include"quit.h"

int main()
{
	int fd[2];
	
	if (pipe(fd)<0)
		quit("pipe",1);
	
	switch (fork())
	{
		case -1:
			quit("Fork fail",2); break;
		case 0:
			close(fd[0]);
			dup2(fd[1],STDOUT_FILENO);
			close(fd[1]);
			execlp("cat", "cat","/etc/passwd",NULL);
			quit("cat",3);
			break;
		default: 
			close(fd[1]);
			dup2(fd[0],STDIN_FILENO);
			close(fd[0]);
			execlp("tr", "tr","'[a-z]'","'[A-Z]'",NULL);
			quit("tr",4);
	}
}
