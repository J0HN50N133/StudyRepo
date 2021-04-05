#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include"quit.h"
#include"arg_check.h"

int main(int argc, char **argv)
{
	int size, fd;
	char buf;
	
	arg_check(2,argc,"Not enough arguments!\n",1);
	
	if ((fd=open(argv[1], O_RDONLY))==-1)
		quit("open",1);
	
	lseek(fd,1,SEEK_END);
	while (lseek(fd,-2,SEEK_CUR) >= 0)
	{
		if (read(fd,&buf,1)!=1)
			quit("read",2);
		if (write(STDOUT_FILENO, &buf, 1)!=1)
			quit("write",3);
	}
	buf='\n';
	write(STDOUT_FILENO, &buf, 1);
	close(fd);
	exit(0);
}
