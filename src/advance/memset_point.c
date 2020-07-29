//
// Created by wangzhumo on 2020/7/29.
//
#include "../../includes/advance/memset_point.h"


void allocateSpace(char **pp){
    char *str = malloc(sizeof(char) * 64);
    strcpy(str,"hello world");

    // 建立关系
    *pp = str;
    // 这里使用 * 取出的是**pp中保持的值，也就是说是 *p的地址
    // 那么把 *p = str 也就是  *p = char *
}


void test01(){
    char *p = NULL;
    allocateSpace(&p);
    // 为什么要给 char **,因为我们要赋值的是 *p 的地址
    // 所以要把指针的指针传递过去，以方便给 *p 的自值赋值他要指向的地址

    printf("%s \n", p);
}

void copyStringValue(){
    char  *str = "hello world";
    char buf[1024];
    // 拷贝str到 buf
    int len = strlen(str);
    for (int i = 0; i < len;i++){
        buf[i] = str[i];
    }
    printf("1 %s \n",buf);

    //如果不加上 '\0' 那就一直往前，直到遇见 '\0'
    buf[len] = '\0';
    //所以自己加上'\0'
    printf("2 %s \n",buf);

    // -----------------------------
    memset(buf, 0, len);
    char *pBuf = buf;
    printf("3 %s \n", buf);
    while (*str != '\0'){
        *pBuf = *str;
        pBuf++;
        str++;
    }
    *pBuf = '\0';
    printf("4 %s \n",buf);

//    while (*pBuf++ = *str++){}
//    遇到 \0  ，因为是先赋值的，所以赋值后
//    while 遇到 \0 就退出循环了
}


void formatString(){
    char buf[1024];
    sprintf(buf,"%d年 %d月 %d日",2020,7,29);
    printf("%s \n",buf);
}