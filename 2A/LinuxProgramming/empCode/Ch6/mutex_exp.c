#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define nloop 10

int counter=0;
//pthread_mutex_t lock;
void *pthread_fun(void *vptr)
{
	int i,val;
	for (i=0;i<nloop;i++)
	{
		//pthread_mutex_lock(&lock);
		val=counter;
		sleep(vptr);
		printf("%x: %d\n", (unsigned int)pthread_self(),counter);
		counter=val+1;
		//pthread_mutex_unlock(&lock);
	}
	pthread_exit(0);
}

int main()
{
	pthread_t tid1,tid2;
	//pthread_mutex_init(&lock,NULL);
	pthread_create(&tid1,NULL,pthread_fun,(void *)1);
	pthread_create(&tid2,NULL,pthread_fun,(void *)2);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	printf("counter=%d\n",counter);
	//pthread_mutex_destroy(&lock);
	exit(0);
}
