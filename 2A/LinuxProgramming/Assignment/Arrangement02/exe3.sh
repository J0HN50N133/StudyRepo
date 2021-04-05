#! /bin/bash

# 对比两个目录dir1和dir2(通过参数给出),
# 将dir2中符合下列条件的文件复制到dir1,并将每一条复制记录存储到文件record中:
# 该文件不在dir1中
# 该文件比dir1中的同名文件更新

[ $# -ne 2 ] && exit 1

# 为了支持相对路径不得不这么做
dir0=$(pwd) ## 原本所在路径
dir1=$1
dir2=$2
if [ ! -d $dir1 ] || [ ! -d $dir2 ];then
    echo "No such file or directory"
    exit 0
fi

for file in $(ls $dir2)
do
        cd $dir0 && cd $dir2
        fileInDir2="$(pwd)/$file" ## 绝对路径的file in dir2
        cd $dir0 && cd $dir1
        if [ ! -e "$file" ]; then
                cp $fileInDir2 ./ && echo -e "$(date) : \n $file does not exist in $dir1.\ncp $dir2/$file $dir1/" >> $dir0/record
        elif [ "$file" -ot "$fileAbs" ]; then # dir1 中的文件更老
                cp $fileInDir2 ./ && echo -e "$(date) : \n $file in $dir1 is older than the one in $dir2.\ncp $dir2/$file $dir1/" >> $dir0/record
        fi
done
