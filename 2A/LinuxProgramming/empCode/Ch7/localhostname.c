#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netdb.h>			//hostent结构体
#include<netinet/in.h>		//in_addr结构体
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>		//inet_ntoa函数

int main()
{
	char name[100]={0};
	if (gethostname(name,sizeof(name))<0)
	{
		herror("gethostname");
		exit(1);
	}
	printf("hostname by gethostname:%s\n",name);
	struct hostent *host;				//保存主机地址信息的结构体
	if ((host=gethostbyname(name))==NULL)			//根据主机名取得地址信息
	{
		herror("gethostbyname");
		exit(2);
	}
	struct in_addr *hostnode;
	hostnode=(struct in_addr*)host->h_addr;
	printf("hostname by hostent:%s\n",host->h_name);				//输出主机名
	printf("IPAddress by inet_ntoa:%s\n",inet_ntoa(*hostnode));		//输出主机IP地址
	long ip;
	ip=ntohl(inet_addr(inet_ntoa(*hostnode)));
	printf("IPaddress converted by inet_addr:%ld\n",ip);
	return 0;
}
