#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
				if (fork() == 0){
								int fd1 = open("txt", O_WRONLY);
								write(fd1, "b", 1);
								printf("%d\n",fd1);
								sleep(1);
				}else{

								int fd2 = open("txt", O_WRONLY);
								printf("%d\n",fd2);
								write(fd2, "a", 1);
				}
				sleep(2);
				return 0;
}
