#! /bin/sh

dir=$1
dir=$2

if [ -d $dir1 ] && [ -d $dir2 ];
then
        ls -l $dir1 | tr -s " " | cut -d" " -f9 | sort > temp1.txt
        ls -l $dir2 | tr -s " " | cut -d" " -f9 | sort > temp2.txt
        comm -3 temp1.txt temp2.txt
else
        echo "Invalid input!"
fi

