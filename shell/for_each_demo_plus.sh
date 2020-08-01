#!/bin/bash
result=0
for((i=0;i<=100;i++))
do
	result=`expr $i + $result`
done
echo $result
