#!/bin/bash

chars="abcdef"
for((i=0;i<7;i++))
do
	arry[$i]=${chars:$i:1}
	echo ${arry[$i]}
done
a=(a b c d)
echo ${a[@]}
echo $a[*]
echo -e "\033[1m"










