#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define MAXSTACK 100
int stack[MAXSTACK][2];
int size=0;
sem_t sem;

void Read1()
{
	FILE *fp=fopen("file1.dat","r");
	while (!feof(fp))
	{
		fscanf(fp,"%d %d", &stack[size][0],&stack[size][1]);
		sem_post(&sem);
		size++;		
	}
	fclose(fp);
}

void Read2()
{
	FILE *fp=fopen("file2.dat","r");
	while (!feof(fp))
	{
		fscanf(fp,"%d %d", &stack[size][0],&stack[size][1]);
		sem_post(&sem);
		size++;		
	}
	fclose(fp);
}

void Compute1()
{
	while (1)
	{
		sem_wait(&sem);
		printf("at size %d, Sum: %d+%d=%d\n",size,stack[size][0],stack[size][1],stack[size][0]+stack[size][1]);
		size--;
		sleep(1);
	}
}

void Compute2()
{
	while (1)
	{
		sem_wait(&sem);
		printf("at size %d, Multiply: %d*%d=%d\n",size,stack[size][0],stack[size][1],stack[size][0]*stack[size][1]);
		size--;
		sleep(1);
	}
}

int main()
{
	pthread_t tid1,tid2,tid3,tid4;
	sem_init(&sem,0,0);
	pthread_create(&tid1,NULL,(void *)Read1,NULL);
	pthread_create(&tid2,NULL,(void *)Read2,NULL);
	pthread_create(&tid3,NULL,(void *)Compute1,NULL);
	pthread_create(&tid4,NULL,(void *)Compute2,NULL);
	
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	pthread_join(tid3,NULL);
	pthread_join(tid4,NULL);
	
	return 0;
}
