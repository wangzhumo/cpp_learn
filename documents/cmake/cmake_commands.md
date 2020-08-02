# CMake Commands


### 指定版本
`cmake_minimun_required(VERSION 3.10.1)`

指定Cmake最低支持的版本号




### 源文件查找
`aux_source_directory({目录} DIR_LIST)`

- 查找指定目录的源文件列表，并把这个列表保存到指定变量`DIR_LIST`
- 只能查找当前目录下的文件，不会对子目录起作用

```cmake
aux_source_directory(src SRC_DIR)
aux_source_directory(src/advance SRC_ADVANCE)
aux_source_directory(src/basic SRC_BASIC)
```




### 添加库
##### 添加一个库

`add_library(<name> [STATIC | SHARED | MODULE] [EXCLUDE_FROM_ALL] source1 ...)`

- 添加一个库，名字是  <name>
- 指定库的类型
  - STACIC 静态库
  - SHARED 动态库
  - MODULE 如果支持`dyld`有效，否则等同 SHARED
- EXCLUDE_FROM_ALL  表示这个库不会被默认构建
- source1 ... sourceN   指定库的源文件



##### 导入预编译库

`add_library(<name> [STATIC | SHARED | MODULE] IMPORTED)`

- 添加一个已经编译好的库，名字为 <name>
- 一般配合`set_target_properties`使用

```cmake
add_library(test SHARED IMPORTED)

set_target_properties(
		test  #库名字
		PROPERTIES IMPORT_LOCATION  #指明设置的参数
		${库路径}/libtest.so    #导入库的路径
)
```



#### 常用的参数

##### 设置可执行文件的输出路径

`EXECUTABLE_OUTPUT_PATH`全局变量

```cmake
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build)
```



##### 设置库文件的输出目录

`LIBRARY_OUTPUT_PATH` 全局变量

```cmake
set(LIBRARY_OUTPUT_PATH ${路径})
```



##### 设置编译参数

`CMAKE_CXX_FLAGS`全局变量

```cmake
# 允许c++11标准、O3优化、多线程。match选项可避免一些cpu上的问题
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -march=native -O3 -pthread" )
```



##### 设置源文件集合

`SOURCE_FILES` 本地自定义变量

```cmake
set(SOURCE_FILES mian.cpp ...)
```



### 设置头文件

```cma
set(INCLUDES  includes/advance/ includes/basic/  )
include_directories(${INCLUDES})
```

可以使用相对/绝对路径



### 添加可执行文件

`add_executable(<name> ${SRC_LIST})`

```cmake
# Set all source
set(ALL_SOURCE ${SRC_DIR} ${SRC_ADVANCE} ${SRC_BASIC})
add_executable(learn_cpp ${ALL_SOURCE})
```



### 链接多个库

`target_link_libraries(<name> lib1 ... libN)`

- 将一个或者多个库链接到目标库文件
- 必须按照互相的依赖关系  lib1 -> lib_sub_1 -> lib_sbu_1_sub_1



```cmake
# Link dirs
set(LIBRARIES ${EVENT_LIBRARIES})
target_link_libraries(learn_cpp  ${LIBRARIES})
```



### 添加子目录可执行文件

`add_subdirectory(sub_dir [binary_dir])`

> sub_dir 指的是包含CMakeList.txt 和源文件的子目录地址
>
> binary_dir  是输出路径，一般不指定

需要包含CMakeList.txt







### 文件操作

```cmake
file(WRITE filename "message to write"... )
file(APPEND filename "message to write"... )
file(READ filename variable [LIMIT numBytes] [OFFSET offset] [HEX])
file(STRINGS filename variable [LIMIT_COUNT num]
[LIMIT_INPUT numBytes] [LIMIT_OUTPUT numBytes]
[LENGTH_MINIMUM numBytes] [LENGTH_MAXIMUM numBytes]
[NEWLINE_CONSUME] [REGEX regex]
[NO_HEX_CONVERSION])
file(GLOB variable [RELATIVE path] [globbing expressions]...)
file(GLOB_RECURSE variable [RELATIVE path]
[FOLLOW_SYMLINKS] [globbing expressions]...)
file(REMOVE [file1 ...])
file(REMOVE_RECURSE [file1 ...])
file(MAKE_DIRECTORY [directory1 directory2 ...])
file(RELATIVE_PATH variable directory file)
file(TO_CMAKE_PATH path result)
file(TO_NATIVE_PATH path result)
file(DOWNLOAD url file [TIMEOUT timeout] [STATUS status] [LOG log]) 
```



### 字符串操作

```cmake
string(REGEX MATCH (regular_expression)(output variable) (input) [(input)...])
string(REGEX MATCHALL (regular_expression)(output variable) (input) [(input)...])
string(REGEX REPLACE (regular_expression)(replace_expression) 
(output variable)
(input) [(input)...])
string(REPLACE (match_string)(replace_string) (output variable)
(input) [(input)...])
string(COMPARE EQUAL (string1) (string2) (output variable))
string(COMPARE NOTEQUAL (string1) (string2) (output variable))
string(COMPARE LESS (string1) (string2) (output variable))
string(COMPARE GREATER (string1) (string2) (output variable))
string(ASCII (number) [(number) ...] (output variable))
string(CONFIGURE (string1) (output variable)[@ONLY] [ESCAPE_QUOTES])
string(TOUPPER (string1) (output variable))
string(TOLOWER (string1) (output variable))
string(LENGTH (string) (output variable))
string(SUBSTRING (string) (begin) (length) (output variable))
string(STRIP (string) (output variable))
string(RANDOM [LENGTH (length)] [ALPHABET (alphabet)] (output variable))
```

