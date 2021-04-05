#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netdb.h>			//hostent结构体
#include<netinet/in.h>		//in_addr结构体
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>		//inet_ntoa函数

int main(int argc, char *argv[])
{
	if (argc<2)
	{
		printf("please provide a hostname.\n");
		exit(1);
	}
	struct hostent* host;				//保存主机地址信息的结构体
	if ((host=gethostbyname(argv[1]))==NULL)			//根据主机名取得地址信息
	{
		herror("gethostbyname");
		exit(2);
	}
	printf("hostname by hostent:%s\n",host->h_name);				//输出主机名
	printf("IPAddress by inet_ntoa:%s\n",inet_ntoa(*(struct in_addr*)host->h_addr));		//输出主机IP地址
	return 0;
}
