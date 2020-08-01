#!/bin/bash
function fundouble()
{
	read -p "please input number" num
	echo $[2*$num]
}

reslut=`fundouble`

# $? mean last command status
echo "fundouble status code  = $?"

# result revice fundouble 
echo "fundouble result value = $reslut"
