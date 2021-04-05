#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/errno.h>

int main(int argc, char **argv)
{
	if (open(argv[1], O_RDONLY)==-1)
	{
		fprintf(stderr, "errno=%d\n",errno);
		perror("open");
	}
	exit(0);
}
