#include<stdio.h>
#include<string.h>
#define BUFSIZE 200
#define ARGVSIZE 40
#define DELIM " \n\t\r"

int main(void)
{
	int i,n;
	char buf[BUFSIZE+1];
	char *clargs[ARGVSIZE];
	n=1;
	printf("Enter a miltiword string: ");
	scanf("%[^\n]",buf);
	clargs[0]=strtok(buf,DELIM);
	while ((clargs[n]=strtok(NULL,DELIM))!= NULL)
		n++;
	clargs[n]=NULL;
	
	for (i=0;i<n;i++)
		printf("Word %d is %s\n", i, clargs[i]);
		
	return 0;
}
