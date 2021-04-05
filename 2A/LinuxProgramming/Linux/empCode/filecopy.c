#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#define BUFSIZE 4096
#define OFLAGS O_WRONLY | O_CREAT | O_TRUNC
#define SMODES S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH

int main()
{
	int fd1,fd2;
	int n;
	char buf[BUFSIZE];
	
	if ((fd1=open("/etc/passwd", O_RDONLY))==-1)
	{	
		perror("open1");
		exit(1);
	}
	if ((fd2=open("passwd.bak", OFLAGS, SMODES))==-1)
	{
		perror("open2");
		exit(2);
	}
	
	while ((n=read(fd1,buf,BUFSIZE)) > 0)
	{
		if (n!=write(fd2,buf,n))
		{
			perror("write");
			exit(3);
		}
	}
	close(fd1);
	close(fd2);
	exit(0);
}
