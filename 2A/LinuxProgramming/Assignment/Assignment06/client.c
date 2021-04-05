#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#define MAX_LINE 256
#define SERVER_PORT 7701
int main(int argc, char *argv[])
{
        FILE *fp;
        struct hostent *hp;
        struct sockaddr_in sin;
        char *host;
        char buf[MAX_LINE];
        int s, len;
        if(argc == 2){
                host = argv[1];
        }else{
                fprintf(stderr, "usage: client [host]\n");
                exit(1);
        }

        hp = gethostbyname(host);
        if(!hp){
                fprintf(stderr, "client: unknown host:%s\n", host);
                exit(1);
        }

        bzero((char *)&sin, sizeof(sin));
        sin.sin_family = AF_INET;
        bcopy(hp->h_addr, (char*)& sin.sin_addr, hp->h_length);
        sin.sin_port = htons(SERVER_PORT);
        if((s = socket(PF_INET, SOCK_STREAM, 0)) < 0){
                perror("socket error:");
                exit(1);
        }
        if(connect(s, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
                perror("connect error:");
                close(s);
                exit(1);
        }
        FILE* passwd = fopen("/etc/passwd", "r");
        while(fgets(buf, sizeof(buf), passwd)){
                buf[MAX_LINE - 1] = '\0';
                len = strlen(buf) + 1;
                send(s, buf, len, 0);
                usleep(5000);
        }
        close(s);
        fclose(passwd);
        return 0;
}
