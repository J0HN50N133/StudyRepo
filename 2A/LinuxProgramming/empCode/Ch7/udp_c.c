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
	int sockfd;
	int z;
	char buf[100],str[79];
	char name[20];
	strcpy(name,getlogin());
	struct sockaddr_in remote_addr;
	remote_addr.sin_family=AF_INET;
	remote_addr.sin_port=htons(PORT);
	remote_addr.sin_addr.s_addr=INADDR_ANY;
	bzero(&(remote_addr.sin_zero),8);
	if ((sockfd=socket(AF_INET,SOCK_DGRAM,0))==-1)
	{
		perror("socket create failure!");
		exit(1);
	}
	while (1)
	{
		printf("Say something to the world:");
		fgets(str,80,stdin);
		sprintf(buf,"%s:%s",name,str);
		if ((z=sendto(sockfd,buf,sizeof(buf),0,(struct sockaddr *)&remote_addr,sizeof(remote_addr)))<0)
		{
			perror("send failure!");
			exit(2);
		}
		printf("Data Sent.\n");
		if (strstr(buf,"stop")!=NULL)
		{
			printf("finish\n");
			break;
		}
	}
	close(sockfd);
	exit(0);
}

