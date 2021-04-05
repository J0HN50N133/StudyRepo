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

#define PORT 8888

int main()
{
	int sockfd, len, z;
	char buf[256];
	struct sockaddr_in local_addr;
	struct sockaddr_in remote_addr;
	printf("waiting for data gram...\n");
	
	local_addr.sin_family=AF_INET;
	local_addr.sin_port=htons(PORT);
	local_addr.sin_addr.s_addr=INADDR_ANY;
	bzero(&(local_addr.sin_zero),8);
	len=sizeof(local_addr);
	
	if ((sockfd=socket(AF_INET,SOCK_DGRAM,0))==-1)
	{
		perror("socket create failure!");
		exit(1);
	}
	if (bind(sockfd, (struct sockaddr *)&local_addr, sizeof(local_addr))==-1)
	{
		perror("bind failure!");
		exit(2);
	}
	while (1)
	{
		if ((z=recvfrom(sockfd,buf,sizeof(buf),0,(struct sockaddr *)&remote_addr,&len))<0)
		{
			perror("receive failure!");
			exit(3);
		}
		buf[z]='\0';
		printf("received data:%s\n",buf);
		if (strstr(buf,"stop")!=NULL)
		{
			printf("finish.\n");
			break;
		}
	}
	close(sockfd);
	exit(0);
}

		
	
