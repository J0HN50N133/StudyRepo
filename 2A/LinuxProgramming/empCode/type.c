#include<stdio.h>

int main(void)
{
	char chours=24, cmin=60, csec=60;	
	short shours=24, smin=60, ssec=60;
	int sum;
	float f1, f2, f3;
	
	/* char和short被自动转换成int */
	printf("Using char, number of seconds in one day is %d\n", chours*cmin*csec);
	printf("Size of cmin = %d\n", sizeof(cmin));
	printf("Size of cmin*csec = %d\n", sizeof(cmin*csec));
	printf("Using short, number of seconds in one day is %d\n", shours*smin*ssec);
	printf("Size of smin = %d\n", sizeof(smin));
	printf("Size of smin*ssec = %d\n", sizeof(smin*ssec));
	
	/* 强制转换所有成员和强制转换最终表达式 */
	f1=f2=f3=2.4;
	sum= (int) f1 + (int) f2 + (int) f3;
	printf("Sum of casting individual components is %d\n", sum);
	sum= (int)(f1+f2+f3);
	printf("Sum of casting entire expression is %d\n", sum);
	
	return 0;
}
