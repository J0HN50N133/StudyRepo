#include<stdio.h>
#include<stdlib.h>

void swap(int *p, int *q);   //形参是指针类型

int main(void)
{
	int x=1, y=2;
	printf("Before swap, x=%d, y=%d\n", x, y);
	
	swap(&x,&y);			//实参是地址
	printf("After swap, x=%d, y=%d\n", x, y);
	
	exit(0);
}

void swap(int *p, int *q)
{
	int temp;
	temp=*p;
	*p=*q;
	*q=temp;
}
