#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	pid_t pid;
	// Before fork
	printf("Before fork:\n");
	pid=fork();
	// After fork
	if (pid >0)			//在父进程中的操作
	{
		sleep(1);		//确保父进程不会先于子进程死亡
		printf("Parent process: PID=%4d, PPID=%4d, child PID=%4d\n", getpid(), getppid(), pid);
	}
	else 
		if (pid==0)		//在子进程中的操作
		{
			printf("Child process: PID=%4d, PPID=%4d\n", getpid(), getppid());
		}
		else 			//创建错误, pid=-1
		{
			printf("Fork error!\n");
			exit(1);
		}
	
	printf("Both processes continue from here\n");
	exit(0);
}
