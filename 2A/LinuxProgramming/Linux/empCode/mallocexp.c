#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>

struct contact
{
	int index;
	char name[20];
	char MTel[12];
	char email[20];
};

int x;

int main()
{
	struct contact *p;
	char ch;
	printf("Add a user? (Y/N): ");
	scanf("%c",&ch);
	//ch=getchar();
	getchar();
	if (ch=='y'||ch=='Y')
	{
		p=(struct contact *)malloc(sizeof(struct contact));
		p->index=++x;
		printf("User Name: ");
		scanf("%[^\n]",p->name);
		printf("Mobile Tel: ");
		scanf("%s",p->MTel);
		printf("Email: ");
		scanf("%s",p->email);
		printf("index:%d\nname:%s\nMobileTel:%s\nEmail:%s\n",p->index,p->name,p->MTel,p->email);
	}
	free(p);
}
