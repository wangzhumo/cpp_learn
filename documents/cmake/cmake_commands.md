# CMake Commands


#### 指定版本
`cmake_minimun_required(VERSION 3.10.1)`

指定Cmake最低支持的版本号




#### 源文件查找
`aux_source_directory({目录} DIR_LIST)`

- 查找指定目录的源文件列表，并把这个列表保存到指定变量`DIR_LIST`
- 只能查找当前目录下的文件，不会对子目录起作用

```cmake
aux_source_directory(src SRC_DIR)
aux_source_directory(src/advance SRC_ADVANCE)
aux_source_directory(src/basic SRC_BASIC)
```




#### 添加库
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

`EXECUTABLE_OUTPUT_PATH`

```cmake
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build)
```



##### 设置库文件的输出目录

```cmake

```

