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
#include<pthread.h>

char recv_buf[1200],send_buf[1024];

void pthread_fun(int sockfd)
{
	int recvbytes;
	while (1)
	{
		if ((recvbytes=recv(sockfd,recv_buf,1200,0))==-1)
		{
			perror("recv failure!");
			exit(1);
		}
		else
		{
			if (recvbytes==0)
			{
				printf("Server is down. Exit...\n");
				exit(1);
			}
			recv_buf[recvbytes]='\0';
			printf("%s\n",recv_buf);
		}
	}
}

int main()
{
	pthread_t id;
	int sockfd;
	struct sockaddr_in server_addr;
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(6666);
	server_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	if ((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		perror("socket failure!");
		exit(2);
	}
	
	if (connect(sockfd,(struct sockaddr *)&server_addr,sizeof(struct sockaddr))==-1)
	{
		perror("connect failure!");
		exit(3);
	}
	
	char name[20];
	printf("input your name: ");
	scanf("%s",name);
	send(sockfd,name,strlen(name),0);
	pthread_create(&id,NULL,(void *)pthread_fun,(void *)sockfd);
	while (1)
	{
		gets(send_buf);
		if (send(sockfd,send_buf,strlen(send_buf),0)==-1)
		{
			perror("send failure!");
			exit(4);
		}
		sleep(1);
	}
	
	close(sockfd);
	pthread_cancel(id);
	exit(0);
}

	
	
	
		
