//
// Created by wangzhumo on 2020/7/29.
//

#include "../../includes/basic/malloc_test.h"

void testCalloc(){
    // int *p1 = malloc(sizeof(int) * 12);
    int *p = calloc(12,sizeof(int));
    // 同时 calloc 还会把这个初始化的内存，清空
    for (int i = 0; i < 12; ++i) {
        printf("%d ",p[i]);
        // 0 0 0 0 0 0 0 0 0 0 0 0
    }
}

void testRealloc(){
    int *p = calloc(12,sizeof(int));
    printf("1 %d \n",p);
    // 我需要更多的内存
    p = realloc(p,sizeof(int) * 20);
    printf("2 %d \n",p);
    //1 560520864
    //2 560521968
    // 两次的地址发生了变化，说明不是一块内存了
    free(p);
}