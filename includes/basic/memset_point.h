//
// Created by wangzhumo on 2020/7/29.
//

#ifndef LEARN_CPP_MEMSET_POINT_H
#define LEARN_CPP_MEMSET_POINT_H
#ifdef __cplusplus
extern "C"{
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 输出特性，在被调用函数中分配内存，主函数使用
void allocateSpace(char **pp);


void test01();


void copyStringValue();

void formatString();

#ifdef __cplusplus
}
#endif // __cplusplus end
#endif //LEARN_CPP_MEMSET_POINT_H
