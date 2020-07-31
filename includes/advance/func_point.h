//
// Created by wangzhumo on 2020/7/31.
//

#ifndef LEARN_CPP_FUNC_POINT_H
#define LEARN_CPP_FUNC_POINT_H
#include <iostream>


void printInt(int a){
    std::cout << "printInt" << a << std::endl;
}

// 函数指针
void testFuncPoint(){
    // 定义一个函数指针
    void(*pFunc) (int);
    // 赋值
    pFunc = printInt;
    pFunc(123);
}

#endif //LEARN_CPP_FUNC_POINT_H
