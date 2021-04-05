#!/bin/bash

{
awk 'BEGIN{ FS=":";
	printf("\t\t\t List of User \n ---------------------------------------------------------\n%-25s %-20s %-60s\n","UserName","GroupName","Shell Path");
}
{ 
	printf("%-25s %-20s %-60s\n",$1,$4,$7);
}
END{ 
	printf("---------------------------------------------------------\n");
}' "/etc/passwd"
} >awk1.out

cut -d: -f7 /etc/passwd | sort | uniq -c >>awk1.out

