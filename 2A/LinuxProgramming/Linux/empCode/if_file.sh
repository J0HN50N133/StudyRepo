#! /bin/bash

[ $# -ne 1 ] && { echo "Usage: $0 file"; exit 1; }

if [ -f "$1" ]
then
        if [ ! -r "$1" ]
        then
                echo "file $1 exists but is not readable"; exit 3;
        else
                echo "File $1 is readable"
                cat $1
        fi
else
                echo "File $1 does not exist"
fi
exit 0;
