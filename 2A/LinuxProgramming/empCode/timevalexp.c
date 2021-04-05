#include<sys/time.h>
#include<unistd.h>
#include<stdio.h>

int main()
{
	struct timeval tv1,tv2;
	struct timezone tz;
	gettimeofday(&tv1,&tz);
	printf("Seconds for now is: %d\n",tv1.tv_sec);
	printf("Micro-seconds for now is: %d\n", tv1.tv_usec);
	gettimeofday(&tv2,&tz);
	printf("Time passed for %d micro-seconds\n", tv2.tv_usec-tv1.tv_usec);
	return 0;
}
