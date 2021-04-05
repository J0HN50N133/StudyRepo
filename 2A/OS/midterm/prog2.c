#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char buffer;
int main(){
				int fd = open("txt", O_WRONLY);
				if (fork() == 0) {
					buffer = 'a';
				}else {
					buffer = 'b';
				}
				write(fd, &buffer, 1);
}
