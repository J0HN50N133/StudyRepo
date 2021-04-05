#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	printf("PID: %4d, PPID: %4d\n", getpid(),getppid());
	printf("UID: %4d, GID: %4d\n", getuid(), getgid());
	printf("SHELL=%s\n", getenv("SHELL"));
	setenv("SHELL", "/bin/sh", 1);
	printf("new SHELL=%s\n", getenv("SHELL"));
	system("ps -al");
	exit (0);
}
