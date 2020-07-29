//
// Created by wangzhumo on 2020/7/28.
//

#ifndef LEARN_CPP_TYPEDEF_DEMO_H   //了防止头文件的重复引用
#define LEARN_CPP_TYPEDEF_DEMO_H


#ifdef __cplusplus     //告诉编译器，这部分代码按C语言的格式进行编译，而不是C++的
extern "C"{
#endif

struct Person1 {
    char name[60];
    int age;
};

typedef struct Person2 {
    char name[60];
    int age;
}myPerson;



typedef struct Person1 mP;

void testForTypedef();

void testValueType();

#ifdef __cplusplus
}
#endif //__cplusplus
#endif //LEARN_CPP_TYPEDEF_DEMO_H
