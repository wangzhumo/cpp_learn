# Cmake

### 变量

Cmka中的所有变量都是 string ，使用 `${变量}`

可以使用 `set()` 以及`unset()`来声明或者移除一个变量

```cmake

# 创建一个变量
set(var_name 1234567)
# 打印
message("var : ${var_name}")

# 创建一个列表
set(list_test Python Java CPP Dart)
# 打印
message("list : ${list_test}")

```





### 操作符

| 类型 | 名称                                                    |
| ---- | ------------------------------------------------------- |
| 一元 | EXIST,COMMAND,DEFINED                                   |
| 二元 | EQUAL,LESS,LESS_EQUAL,GREATER(大于),GREATER_EQUAL ..... |
| 逻辑 | NOT,AND,OR                                              |

优先级：

（）  >   一元  > 二元  >  逻辑



### 布尔常量值

| 类型  | 值                                                           |
| ----- | ------------------------------------------------------------ |
| true  | 1,ON,YES,TRUE,Y,非零值                                       |
| false | 0,OFF,NO,FALSE,N,IGNORE,NOTFOUND,空字符串，以 `-NOTFOUND`结尾的字符串 |



### 条件语句

```cmake
if (表达式)
	COMMAND(ARGS)	
elseif (表达式) 	
	COMMAND(ARGS)
else (表达式)
	COMMAND(ARGS)
endif (表达式)	
```



### 循环语句

#### while

```cmake
while (表达式)
	COMMAND(ARGS)
	
	continue() #跳出本次循环
	break() #可以跳出整个循环
endwhile(表达式)
```



#### foreach

```cmake
foreach (item 1 2 3)
	COMMAND(ARGS)
	
	continue() #跳出本次循环
	break() #可以跳出整个循环
endforeach(item)	

OR

foreach (item RANG ${END})
	COMMAND(ARGS)
	
	continue() #跳出本次循环
	break() #可以跳出整个循环
endforeach(item)

OR

foreach (item RANG ${START} ${END} ${STEP})
	COMMAND(ARGS)
	
	continue() #跳出本次循环
	break() #可以跳出整个循环
endforeach(item)
```





### 函数

```cmake
function (<func_name> [arg1] [arg2] ... [argN])
	COMMAND()
endfunction(<func_name>)	

# 调用
func_name(args...)
```

