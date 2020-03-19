#include <iostream>
#include <string>


int a = 0;      //(GVAR) 全局初始化区
int* p1;        //(bss)全局未初始化区


//Cpp的内存
int main(){        //(text)代码区

    int b = 1;          //(stack)栈区变量 
    char s[] = "ac";    //(stack)栈区变量
    int* p2 = NULL;     //(stack)栈区变量
    
    char const *p3 = "123456";    //123456 常量区
                                  //p3 (stack)栈区变量 

    static int c = 0 ;            //(GVAR)全局静态初始化区
    p1 = new int(10);             //heap堆区
    p2 = new int(20);             //heap堆区
    char* p4 = new char[7];       //heap堆区

    //strcpy_s(p4,7,"123456");          //(text)代码区


    
    return 0;     //(text)代码区
}