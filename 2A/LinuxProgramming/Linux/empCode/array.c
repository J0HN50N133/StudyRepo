#include<stdio.h>
#include<stdlib.h>
#define MAX 3

int main(void)
{
	short counter=0;
	int int_array[MAX];
	char char_array[4]={'Y','E','S'};
	
	/* int_array accessing */
	int_array[0]=1; int_array[1]=2; int_array[2]=3;
	printf("int_array[0] = %d\n",int_array[0]);
	printf("The complete elements of int_array are: ");
	while (counter<MAX)
	{
		printf("%d  ",int_array[counter]);
		counter++;
	}
	printf("\n");
	
	/* char_array accessing */
	char_array[3]='\0';
	printf("char_array[0] = %c\n",char_array[0]);
	printf("char_array is a string: %s\n",char_array);
	printf("char_array = %p\n",char_array);
	
	return 0;
}
