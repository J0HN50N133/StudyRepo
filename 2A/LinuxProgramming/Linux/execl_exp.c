#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	execl("/bin/cat", "cat", "/etc/passwd", (char *) 0);
	printf("execl Error!\n");
	exit(1);
}
