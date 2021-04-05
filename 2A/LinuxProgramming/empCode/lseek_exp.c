#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

void quit(char *prompt, int status);
void arg_check(int wanted_argc, int argc, char * prompt,int status);
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

void arg_check(int wanted_argc, int argc, char *prompt,int status){

	if(argc < wanted_argc){
		fprintf(stderr, prompt);
		exit(status);
	}
}

void quit(char *prompt, int status){
	fprintf(stderr, prompt);
	exit(status);
}
