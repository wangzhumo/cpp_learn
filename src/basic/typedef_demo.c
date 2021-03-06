//
// Created by wangzhumo on 2020/7/28.
//
#include "../../includes/basic/typedef_demo.h"


void testForTypedef() {
    // 普通的初始化
    struct Person1 p = {"nameA", 19};
    // 使用typedef的别名
    // mPre p2 = {"nameB", 20};
    printf("%s", p.name);
}

void testValueType() {
    char *p1, p2;
    // 其中， * 修饰p1 也就是说，p1是一个指针
    // 而 p2 就是一个char类型
    typedef char *pP;
    pP p3, p4;
    //此时 p3,p4就都是char*的类型了

    // 等于
    char *p5, *p6;
}


void testStructInHeap() {
    // 在栈区分配
    struct Person1 personList[] = {
            {"name_1", 18},
            {"name_2", 18},
            {"name_3", 18},
    };


    // 在堆区创建
    struct Person1 *pArr = malloc(sizeof(struct Person1) * 4);
    for (int i = 0; i < 4; ++i) {
        sprintf(pArr[i].name, "name_%d", i);
        pArr[i].age = 18 + i;

    }


    //用完了需要释放，heap区的数据
    if (pArr != NULL) {
        free(pArr);
        pArr = NULL;
    }
}