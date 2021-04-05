#!/bin/bash

total=0

function checknumber(){
	num1=$num
	flag=0
	while([ $num1 ])
	do
	num2=${num1:0:1}
	case "$num2" in
	[0-9])
	;;

	[.]) 
	flag=$((flag+1))
	if [ "$flag" -gt "1" ]
	then
		return 0
	fi
	;;

	*) 
	return 0
	;;

	esac
	num1=${num1#$num2}
	done


	return 1
}


for num in "$@"
do
	if [ "$num" = "end" ]
	then
		echo $total
		exit 0
	fi
	checknumber $num
	flag=`echo $?`
	if [ "$flag" -eq "0" ]
		then
		echo "Please input a number."
		echo "exit 1"
		exit 1
	else
		total=$(echo "scale=2;($total+$num)/1"|bc)
	fi
done

echo $total
