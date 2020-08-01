# Shell 的简单认识

### shell 的文件

```shell
#!/bin/bash            这里引入
#File by wangzhumo     表明作者
echo "wangzhumo"       简单的输出
```



### shell的参数

| code | desc                                  |
| ---- | ------------------------------------- |
| $0   | 当前程序的名称                        |
| $n   | 输入参数 n = 1...n ，代表了第几个参数 |
| $*   | 输入的所有参数                        |
| $#   | 输入参数的个数                        |
| $?   | 命令执行的状态，一般返回0   表示成功  |

```shell
#!/bin/bash  
#File by wangzhumo
echo "wangzhumo"

echo "###############"
echo $0
echo $1
echo $2

echo "###############"

echo "this \$? is $?"
echo "this \*? is $*"
echo "this \#? is $#"


result:
# wangzhumo @ ubuntu in ~/code/shell [3:25:21] 
$ ./shell_demo.sh wangzhumo wangzhumo2
wangzhumo
###############
./shell_demo.sh
wangzhumo
wangzhumo2
###############
this $? is 0    成功返回的 0 
this \*? is wangzhumo wangzhumo2
this \#? is 2
```

### shell 算术运算符

| +    | -    | *    | /    | %    | =    | ==   | !=   |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 加   | 减   | 乘   | 除   | 取余 | 赋值 | 相等 | 不等 |



### shell表达式          

```shell
[ $参数1<$参数2 ]   
```

注意，表达式必须在 `[]`方括号中间，而且一定有空格



### shell 字符串运算符

| code | desc                                         |
| ---- | -------------------------------------------- |
| =    | 相等                                         |
| !=   | 检查两个字符串是否不相等    [ $str1 != $str2 ] |
| -z   | 检查字符串长度是否为 0 , 为0则返回 true      |
| -n   | 检查字符串长度是否为 0 , 不为0则返回 true    |
| $    | 检查是否字符串为空                           |




### shell 逻辑运算

| code | desc             |
| ---- | ---------------- |
| -f   | 判断文件是否存在 |
| -d   | 判断目录是否存在 |
| -eg  | 等于（整形）     |
| -ne  | 不等于           |
| -le  | 小于             |
| -ge  | 大于或者等于     |
| -a   | 两者都成立       |
| -o   | 其中一种成立     |






### shell的一些命令

- 循环

  ```shell
  for 变量 in 字符串
  do
    语句1
  done 
  ```

- 接受执行结果

  ```shell
  ` 表达式 `
  ```

- 输出序列

  ```shell
  seq 1 15
  ```

- expr

  expr命令是一个手工命令行计数器，用于在UNIX/LINUX下求表达式变量的值，

  一般用于整数值，也可用于字符串

  ```shell
  expr 表达式
  ```

  **表达式说明:**

  - 用空格隔开每个项；
  - 用 / (反斜杠) 放在 shell 特定的字符前面；
  - 对包含空格和其他特殊字符的字符串要用引号括起来

- find

  ```shell
  $ find . -name "*.sh"
  ./shell_demo.sh
  ./for_each_demo_plus.sh
  ./for_each_demo.sh
  
  ```

- read

  ```shell
  read $变量
  wangzhumo
  
  echo $变量
  wangzhumo
  
  # wangzhumo @ ubuntu in ~/code/shell [4:06:11] 
  $ read name
  wangzhumo
  
  # wangzhumo @ ubuntu in ~/code/shell [4:07:26] 
  $ echo $name
  wangzhumo
  ```

- 指向  < or >

  ```shell
  命令 > text.txt
  ```

- if

  - 第一种

    ```shell
    if(表达式);
    fi
    ```
    
  - 第二种
  
    ```shell
    if(表达式);then
        语句
    else
    	语句
    fi	
    ```


- shell function 函数

  - 第一种

    ```shell
    name()
    {
        command;
        ...
      
    }
    ```
  
    
  
  
- 第二种
  
  ```shell
    [ function ] name [ () ]
    {
      command;
      [return int;]
    }
    ```
  
    
  
  
  
   

### shell的Demo

#### for循环

```shell
#!/bin/bash
for i in `seq 1 15`
do
        echo "$i"
done
   
```



##### for循环 + 相加

```shell
#!/bin/bash
result=0
for((i=0;i<=100;i++))
do
        result=`expr $i + $result`
done
echo $result


要注意上面的  expr $i + $result 加号左右的空格。
```



##### while循环

```shell
#!/bin/bash
result=0
while((result<100))   // 这里是算术的判断
do
        echo $result
        result=`expr $result + 1`
done


result2=0
while [[ $result2 -lt 100 ]]   // 这里是逻辑条件语句
do
        echo $result2
        result2=`expr $result2 + 1`
done

```



##### 读写文件

```shell
#!/bin/bash
while read line
do
        echo $line
done</home/wangzhumo/code/shell/input.txt


/home/wangzhumo/code/shell/input.txt  这个文件作为输入
```



#### if 条件输入

```shell
#!/bin/bash
NUM1=100
NUM2=200
if(($NUM1>$NUM2));then
        echo "num1 > num2"
else
        echo "num1 < num2"
fi


if [ ! -d /home/wangzhumo/code/shell/empty ]; then
        mkdir -p /home/wangzhumo/code/shell/empty
else
        echo "dir already exist"
fi

  

then ----> fi
要注意 [ 两边的空格 ]
```



##### function

```shell
#!/bin/bash
function test()
{
        echo $1
        cc="param cc = value"
        echo $cc
        echo "call a function"
}


# call function

test 100

```







