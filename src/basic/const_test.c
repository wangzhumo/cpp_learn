//
// Created by wangzhumo on 2020/7/30.
//

#include "../../includes/basic/const_test.h"

void testConst(){
    struct Person p = {"name",20};
    printf("Person name = %s  ,age = %d", p.name, p.age);
    testChangePerson(&p);
}

// 修饰参数，表示这个参数不可以修改
void testChangePerson(const struct Person *person){
    //person->age = 12;
    //不可以修改
    printf("Person name = %s  ,age = %d", person->name, person->age);
}

// 使用普通变量初始化 const ，可以修改
void testConstWithVar(){
    int a = 10;
    // 这样的话，会直接放在符号表中，就无法改变了
//    const int b = 10;

    // 使用普通变量初始化,会分配空间
    const int b = a;
    printf("A addr = %d",&a);  //7077340B
    printf("B addr = %d \n",&b);  //7077336A
    // int b 不是引用了 a 的地址，只是复制了它的值

    // 直接编译错误
    //b = 10;

    int *p = (int *) &b;
    *p = 1000;
    printf("A = %d",b);
}