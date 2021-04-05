#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netdb.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<errno.h>
#include<sys/wait.h>
#include<unistd.h>

#define SERVERPORT 80
#define MAXSIZE 4096

int main(int argc,char *argv[])
{
	int sockfd, recvbytes;
	char buf[MAXSIZE];
	struct hostent *host;
	struct sockaddr_in serv_addr;
	if (argc<2)
	{
		printf("Please enter the server's hostname!");
		exit(1);
	}
	if ((host=gethostbyname(argv[1]))==NULL)
	{
		herror("gethostbyname failure!");
		exit(2);
	}
	printf("Connecting to %s:%d\n",inet_ntoa(*(struct in_addr*)host->h_addr),SERVERPORT);
	if ((sockfd=socket(AF_INET,SOCK_STREAM, 0))==-1)
	{
		perror("socket create failure!");
		exit(3);
	}
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(SERVERPORT);
	serv_addr.sin_addr=*((struct in_addr *)host->h_addr);
	bzero(&(serv_addr.sin_zero),8);
	
	if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(struct sockaddr))==-1)
	{
		perror("connect failure!");
		exit(4);
	}
	printf("connected to %s:%d\n",inet_ntoa(*(struct in_addr*)host->h_addr),ntohs(serv_addr.sin_port));
	if ((recvbytes=recv(sockfd,buf,MAXSIZE,0))==-1)
	{
		perror("receive failure!");
		exit(5);
	}
	buf[recvbytes]='\0';
	printf("Received data:%s\n",buf);
	close(sockfd);
	exit(0);
}

