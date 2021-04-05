#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int x=10;
	int *p=&x;
	int *q;
	printf("p=%p\n",p);
	printf("x=%d, *p=%d\n",x,*p);
	x=20;
	printf("Assign x=20, *p=%d\n",*p);
	*p=30;
	printf("Assign *p=30, x=%d\n",x);
	q=p;
	printf("Assign q=p, q=%p, *q=%d\n",q,*q);
	*q=40;
	printf("Assign *q=40, *p=%d\n", *p);
	
	printf("The size of p is: %d\n",sizeof(p));
	printf("The size of *p is: %d\n",sizeof(*p));
	
	return 0;
}
