/* size of the basic types */

#include<stdio.h>

int main(void) 
{
	printf("Size of char: %1d byte\n",sizeof(char));
	printf("Size of short: %1d byte\n",sizeof(short));
	printf("Size of int: %1d byte\n",sizeof(int));
	printf("Size of long: %1d byte\n",sizeof(long));
	printf("Size of float: %1d byte\n",sizeof(float));
	printf("Size of double: %1d byte\n",sizeof(double));
	printf("Size of 5: %1d byte\n",sizeof(5));
	printf("Size of 5L: %1d byte\n",sizeof(5L));
	return 0;
}
