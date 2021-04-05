#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_t utid;

void printid(const char *s)
{
	pid_t pid;
	pthread_t tid;
	pid=getpid();
	tid=pthread_self();
	printf("%s. pid=%u, tid=%lu \n",s,pid,tid);
}

void *thread_fun(void *arg)
{
	printid(arg);
	return NULL;
}

int main()
{
	int r;
	r = pthread_create(&utid,NULL,thread_fun, "This is new thread");
	if (r!=0)
	{
		fprintf(stderr, "Fail to create a thread: %s\n", strerror(r));
		exit(1);
	}
	printid("This is the current process");
	sleep(2);
	return 0;
}

