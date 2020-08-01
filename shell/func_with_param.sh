#!/bin/bash
result=1;

# c like
function factorial()
{
for((i=1;i<$1;i++))
do
	result=$[ $result * $i ]
done
echo "$1 reslut = $result"

factorial2 $1
}



#shell like
result2=1
function factorial2()
{
	for i in `seq $1`
	do
		let result2=$result2*$i
	done
	echo "$1 result2 = $result2"
}

# here val params
# factorial 10

# here is param from cmd
factorial $1
