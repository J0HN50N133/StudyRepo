#! /bin/bash

cat /etc/passwd | awk -F: 'BEGIN {
Format="%-25s%-25s%-25s\n"
SPLITLINE="---------------------------------------------------------------------------\n"

printf ("\t%30s\n","List of Users")
printf SPLITLINE
printf (Format, "UserName", "GroupName", "Shell")
}
{
        count[$7]++
        cmd=sprintf("id -gn %s", $1) # trick to get groupName
        cmd |& getline groupName
        close(cmd)
        printf(Format, $1, groupName, $7)
}
END{
printf SPLITLINE
for (i in count)
        printf ("%s:%d\n", i, count[i])
}' > awk1.out
