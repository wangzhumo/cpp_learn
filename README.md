# cpp_learn

## 基础知识

`demo_1.cpp` 基本类型长度

`memory_1.cpp` 内存结构

`memory_leak.cpp` 内存泄漏/智能指针

`unique_ptr.cpp` 内存泄漏/智能指针

`weak_shared_2.cpp` 内存泄漏/智能指针

`weak_shared_ptr.cpp` 内存泄漏/智能指针

`pointer_x.cpp`  指针

`reference_1.cpp`  引用

`string_x.cpp`  String的使用

`struct_union.cpp` 结构体/联合体及其内存

`syntax_if_switch.cpp`  for/switch/if

`override_1.cpp` 函数重载与指针函数

`namespace_1.cpp`  命名空间

`fib_fun.cpp`  斐波那契数列的递归

## 进阶知识

`Complex.cpp` 类/重载操作符/函数

`singleton.cpp` 单例模式

`observalbe.cpp` 观察者模式

`cast_cpp.cpp` 类型转换

`adapter.cpp`  适配器模式

`generic_type.cpp`  泛型

`stl_container.cpp`  容器list,map等

`stl_functor.h`   仿函数

`stl_transform.h`  lambda表达式/transform/find

`stl_iterator.h`  迭代器的使用

`thread_demo.h` 线程的简单认识

`typedef_demo.h` 使用typedef/ extern "C" 

`memset_point.c` 指针赋值/字符串拷贝/格式化字符串






# NOTE

### Cmake

1. 其中LANGUAGES如果 C CPP 都有使用
```cmake
## PROJECT NAME & VERSION
project(learn_cpp VERSION 1.0.1 LANGUAGES C CXX)
```

### Code

1.无符号的数据与有符号的数据做操作，会先吧有符号的转化为无符号再操作
```c
unsinged int a = 10;
if (a - 20 > 0){
    printf("大于 0 ");
}else{
    printf("小于 0 ");
}

shell:
大于 0
```