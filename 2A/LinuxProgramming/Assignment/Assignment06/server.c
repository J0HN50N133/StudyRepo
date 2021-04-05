#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <pthread.h>
#include <unistd.h>
#define MAX_PENDING 5
#define MAX_LINE 256
#define SERVER_PORT 7701
void* server_func(void* s);
int main(int argc, char *argv[])
{
        struct sockaddr_in sin;
        socklen_t len;
        int s;
        bzero((char*)&sin, sizeof(sin));
        sin.sin_family = AF_INET;
        sin.sin_addr.s_addr = INADDR_ANY;
        sin.sin_port = htons(SERVER_PORT);

        if((s = socket(PF_INET, SOCK_STREAM, 0)) < 0){
                perror("simplex-talk: socket");
                exit(1);
        }
        if((bind(s, (struct sockaddr *)&sin, sizeof(sin))) < 0){
                perror("simplex-talk: bind");
                exit(1);
        }
        listen(s, MAX_PENDING);
        while(1){
                int* new_s = malloc(sizeof(int));
                len = sizeof(sin);
                if((*new_s = accept(s, (struct sockaddr*)&sin, &len)) < 0){
                        perror("simplex-talk: accept");
                        exit(1);
                }
                pthread_t utid;
                int r = pthread_create(&utid, NULL, server_func, new_s);
                if(r != 0){
                        fprintf(stderr, "Fail to connect with client: %s\n", strerror(r));
                }
        }
        return 0;
}

void* server_func(void* args){
        int *s= (int *)args;
        char* buf = malloc(MAX_LINE);
        while(recv(*s, buf, sizeof(buf), 0)){
                fputs(buf, stdout);
        }
        close(*s);
        free(s);
        free(buf);
        pthread_exit(0);
}
