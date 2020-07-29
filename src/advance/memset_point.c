//
// Created by wangzhumo on 2020/7/29.
//
#include "../../includes/advance/memset_point.h"


void allocateSpace(char **pp){
    char *str = malloc(sizeof(char) * 64);
    strcpy(str,"hello world");

    // 建立关系
    pp = str;
}


void test01(){
    char *p = NULL;
    allocateSpace(&p);
    // 为什么要给 char **,因为我们要赋值的是 *p 的地址
    // 所以要把指针的指针传递过去，以方便给 *p 的自值赋值他要指向的地址

    printf("%s \n", p);
}