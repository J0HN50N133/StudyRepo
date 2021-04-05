#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread1(void *arg)
{
	for (int i=0;i<6;i++)
	{
		printf("This is pthread1.\n");
		sleep(1);
	}
	printf("Pthread1 exits.\n");
	pthread_exit(0);		
}

void *thread2(void *arg)
{
	for (int i=0;i<3;i++)
	{
		printf("This is pthread2.\n");
		sleep(1);
	}
	printf("Pthread2 returns.\n");
	return(1);
}

int main()
{
	pthread_t tid1,tid2;
	int i,rt;
	void *rtv;
	rt = pthread_create(&tid1,NULL,thread1,NULL);
	if (rt!=0)
	{
		printf("Create pthread1 failed: %s\n",strerror(rt));
		exit(1);
	}
	rt = pthread_create(&tid2,NULL,thread2,NULL);
	if (rt !=0)
	{
		printf("Create pthread2 failed: %s\n",strerror(rt));
		exit(2);
	}
	rt = pthread_join(tid1,&rtv);
	if (rt!=0)
		printf("Can't join with thread1: %s\n",strerror(rt));
	printf("Thread1 exit code: %d\n",(int)rtv);
	rt = pthread_join(tid2,&rtv);
	if (rt!=0)
		printf("Can't join with thread2: %s\n",strerror(rt));
	printf("Thread2 exit code: %d\n",(int)rtv);
	exit(0);
}
