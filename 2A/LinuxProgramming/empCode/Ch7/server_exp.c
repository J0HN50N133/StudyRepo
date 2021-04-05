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

#define SERVERPORT 8000
#define BACKLOG 10

void printlocaladdr()
{
	char hname[100]={0};
	gethostname(hname,sizeof(hname));
	struct hostent *host;
	host=gethostbyname(hname);
	printf("Server name is: %s\n",hname);
	printf("Server IP address is:%s\n",inet_ntoa(*((struct in_addr *)host->h_addr)));
	printf("Server port is: %d\n",SERVERPORT);
}

int main(int argc, char *args[])
{
	int sockfd, clientfd;
	struct sockaddr_in my_addr;
	struct sockaddr_in remote_addr;
	int sin_size;
	printlocaladdr();	
	if ((sockfd=socket(AF_INET, SOCK_STREAM,0))==-1)
	{
		perror("socket failure!");
		exit(1);
	}
	my_addr.sin_family=AF_INET;
	my_addr.sin_port=htons(SERVERPORT);
	my_addr.sin_addr.s_addr=INADDR_ANY;
	bzero(&(my_addr.sin_zero),8);
	if (bind(sockfd,(struct sockaddr *)&my_addr, sizeof(struct sockaddr))==-1)
	{
		perror("bind failure!");
		exit(2);
	}
	if (listen(sockfd,BACKLOG)==-1)
	{
		perror("listen failure!");
		exit(3);
	}
	
	printf("Listening at: %s:%d\n",inet_ntoa(my_addr.sin_addr),SERVERPORT);
	while (1)
	{
		sin_size=sizeof(struct sockaddr_in);
		if ((clientfd=accept(sockfd,(struct sockaddr *)&remote_addr,&sin_size))==-1)
		{
			perror("accept failure!");
			continue;
		}
		printf("accepting connection from %s\n",inet_ntoa(remote_addr.sin_addr));
		if (!fork())
		{
			if (send(clientfd, "connection established.\n", 26, 0) ==-1)
				perror("send failure!");
			close(clientfd);
			exit(0);
		}
	close(clientfd);
	}
}

