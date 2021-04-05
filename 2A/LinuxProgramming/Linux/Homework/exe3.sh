#!/bin/bash

dir1=$1
dir2=$2

list1=`ls $dir1`
list2=`ls $dir2`

for file2 in $list2
do
	tag=0
	for file1 in $list1
	do
		if [ "$file1" = "$file2" -a "$dir1/$file1" -nt "$dir2/$file2" ]
		then
		tag=1
		break
		fi
	done

	if [ "$tag" -eq "0" ]
	then
	cp $dir2/$file2 $dir1
	echo "cp $dir2/$file2 $dir1" >> record
	fi
done

