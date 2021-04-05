#! /bin/bash

function processFile() {
        if [ ! -e $1 ]; then
                echo "cannot access '$1': No such file or directory."
                return 1
        elif [ -d $1 ] ; then
                [ -e "$1"".tar.gz" ] && echo "file already exist, skip" && exit 1;
                tar -czf $1".tar.gz" $1
        elif [ -f $1 ]; then
                case $1 in
                *.tar.bz2)   tar -kxvjf $1 ;;
                *.tar.gz)    tar -kxvzf $1 ;;
                *.tar.xz)    tar -kxvJf $1 ;;
                *.tar)       tar -kxvf $1     ;;
                *.tbz2)      tar -kxvjf $1    ;;
                *.tgz)       tar -kxvzf $1    ;;
                *)           echo "don't know how to extract '$1'... and it's content is " && cat $1;;
                esac
        fi
}

if [ $# -eq 0 ]; then
        cat 1>&2 <<- "EOF"
Usage: exe1.sh [-option] [file ...]
Options:
       -r, --remove    Remove archive after unpacking.
EOF
        exit 1
else
        for i in $@
        do
                processFile $i
        done
fi
