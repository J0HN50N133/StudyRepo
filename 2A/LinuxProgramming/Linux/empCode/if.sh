#! /bin/sh
if [ -z "$*" ]
then
        echo "No argument is given"
        exit 1
else
        echo -e "The argument is $@\n"
        echo "$*"
fi
exit 0
