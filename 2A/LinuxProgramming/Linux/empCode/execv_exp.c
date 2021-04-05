#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
	execv("/bin/cat", argv);
	printf("execv Error!\n");
	exit(1);
}
