#include<stdlib.h>
#include<stdio.h>

int main()
{
	int i,j,k;
	printf("The seed is %d.\n",(int)time(0));
	srand((int)time(0));
	for (i=0;i<10;i++)
	{
		j=1+(int)(10.0*rand()/(RAND_MAX+1.0));
		k=rand()%50+1;
		printf("%d  %d  ", j,k);
	}
	printf("\n");
}

