#由用户输入一组数（以end表示输入结束），输出这些数的和，
#结果保留2位小数。要求使用函数做输入类型检查，并给出错误提示信息。

#! /bin/bash
UsageInfo(){
        [ -n "$1" ] && echo "Invalid input $1. Exiting" 1>&2
        echo "Usage: ./exe2.sh [nums sequence] end" 1>&2
        exit 1
}
## without input
[ -z "$*" ] && UsageInfo && exit 1

res=0
for i in $@
do
        if [ "$i" = "end"  ]; then
                echo "$res" | awk '{printf("%.2f", $1)}' && exit 0
        fi
        # 判断是否是一个合法的浮点数, 不是则打印帮助信息并退出, 是则进行加法
        [ ! -z "$(echo "$i" | sed -r 's/^[-\+]?[0-9]+(\.[0-9]+)?$//g')" ] && UsageInfo "$i"
        res=$(echo "$res $i" | awk '{printf("%f", $1+$2)}')
done
UsageInfo
