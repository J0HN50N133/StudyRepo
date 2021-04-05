#include<stdio.h>
#define PI 3.14

int main(void)
{
	int number;
	float area;
	
	number=65;
	printf("The character %c has the ASCII value %d\n",number,number);
	number=48;
	printf("The character %c has the ASCII value %d\n",number,number);
	
	area=PI*number*number;
	printf("The area of a circle of radius %d = %.4f\n",number,area);
	
	return 0;
}
