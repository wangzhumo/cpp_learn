#include <iostream>

int a = 0;      //(GVAR) 全局初始化区
int* p1;        //(bss)全局未初始化区


//Cpp的内存
int main(){        //(text)代码区

    int b = 1;          //(stack)栈区变量 
    char s[] = "ac";    //(stack)栈区变量
    int* p2 = NULL;     //(stack)栈区变量
    
    char const *p3 = "123456";    //123456 常量区
                                  //p3 (stack)栈区变量 
    

    
    return 0;
}