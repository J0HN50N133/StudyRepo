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

#define COUNT 5

int socket_fd[COUNT];

void pthread_fun(int client_fd)
{
	char msg[1200];
	char buf[1024];
	int i, recvbytes;
	char name[20];
	recvbytes=recv(client_fd,name,20,0);
	name[recvbytes]='\0';
	printf("%s enters the chatroom.\n",name);
	for (i=0;i<COUNT;i++)
	{
		if (socket_fd[i]==-1)
			continue;
		else
		{
			msg[0]='\0';
			sprintf(msg,"%s enters the chatroom.",name);
			if (send(socket_fd[i],msg,strlen(msg),0)==-1)
			{
				perror("send failure!");
				exit(2);
			}
		}
	}
	
	while (1)
	{
		if ((recvbytes=recv(client_fd,buf,1024,0))==-1)
		{
			perror("recv failure!");
			exit(1);
		}
		if (recvbytes==0)
		{
			printf("%s leaves the chatroom.\n",name);
			break;
		}
		buf[recvbytes]='\0';
		for (i=0;i<COUNT;i++)
		{
			if (socket_fd[i]==-1)
				continue;
			else
			{
				msg[0]='\0';
				sprintf(msg,"%s says: %s",name,buf);
				if (send(socket_fd[i],msg,strlen(msg),0)==-1)
				{
					perror("send failure!");
					exit(2);
				}
			}
		}
	}
	
	close(client_fd);
	for (i=0;i<COUNT;i++)
	{
		if (socket_fd[i]==client_fd)
			socket_fd[i]=-1;
	}
	pthread_exit(0);
}

int main()
{
	int i;
	for (i=0;i<COUNT;i++)
		socket_fd[i]=-1;
	
	pthread_t id;
	int sockfd,client_fd;
	socklen_t sin_size;
	struct sockaddr_in my_addr;
	struct sockaddr_in remote_addr;
	if ((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		perror("socket create failure!");
		exit (3);
	}
	my_addr.sin_family=AF_INET;
	my_addr.sin_port=htons(6666);
	my_addr.sin_addr.s_addr=INADDR_ANY;
	bzero(&(my_addr.sin_zero),8);
	
	if (bind(sockfd,(struct sockaddr *)&my_addr, sizeof(struct sockaddr))==-1)
	{
		perror("bind failure!");
		exit(4);
	}
	printf("chatroom server starts. listening to port 6666...\n");
	
	if (listen(sockfd,10)==-1)
	{
		perror("listen failure!");
		exit(5);
	}
	
	i=0;
	while (1)
	{
		sin_size=sizeof(struct sockaddr);
		if ((client_fd=accept(sockfd, (struct sockaddr *)&remote_addr, &sin_size))==-1)
		{
			perror("accept failure!");
			exit(6);
		}
		
		while (socket_fd[i]!=-1)
			i=(i+1)%COUNT;
		socket_fd[i]=client_fd;
		pthread_create(&id,NULL,(void *)pthread_fun, (int *)client_fd);
	}
	close(sockfd);
	exit(0);
}
	
		
