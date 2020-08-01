#!/bin/bash
result=0
while((result<100))
do
	echo $result
	result=`expr $result + 1` 
done


result2=0
while [[ $result2 -lt 100 ]]
do
	echo $result2
	result2=`expr $result2 + 1`
done
