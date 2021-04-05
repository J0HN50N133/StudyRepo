#!/bin/bash

file1=$1


if [ ! -e "$file1" ]
then
	echo "cannot access '$file1':No such file or firectory"
	exit 1
elif [ -f "$file1" ];then
	if [ "${file1##*.}" = "gz" ]
	then
		file2=${file1%%".gz"}
		if [ "${file2##*.}" = "tar" ]
		then
			tar -zxvf $file1
		else
			gzip -d $file1
		fi
	elif [ "${file1##*.}" = "zip" ]
	then
		unzip $file1
	elif [ "${file1##*.}" = "tar" ]
	then
		tar -xvf $file1
	else
		cat $file1
	exit 0
	fi
elif [ -d "$file1" ]
then
	tar -cvf $file1".tar" $file1
fi
