#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

int fd;

void* helper(void* arg)
{
	write(fd, "a", 1);
	return NULL;
}

int main(){
	fd = open("txt", O_WRONLY);
	pthread_t thread;
	pthread_create(&thread, NULL, helper, NULL);
	write(fd, "b", 1);
}
