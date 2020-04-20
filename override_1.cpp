#include <iostream>

using namespace std;


//函数重载 与 C++的 Name Mangling
int test(int a);

int test(double a);

int test(int a ,int b);

//当前的这个方法是和 int test(int a); 冲突的。
int test(int a =1 ,int b =2);




// ?test@@YAHH@Z
// ?test@@YAHN@Z
// ?test@@YAHHN@Z   is ： - “int __cdec1 test(int,int)
//可以使用undname工具查看这个东西



//override
int main(){

    //函数指针 : 指向函数入口地址的指针
    //此时可以使用函数指针来直接指向第一个方法
    int (*pf)(int); 
    //这个函数指针是指   函数指针名为p ,返回值是int  参数是int的一个函数
    pf = test;

    //eg
    //int add(int nLeft,int nRight);  函数定义 
    //int (*pf)(int,int);    未初始化的函数指针
    //pf = add;              通过赋值使得函数指针指向具体函数   

    pf(12);

    //一般形式 : 函数的返回数据类型 （*指针变量名字）（参数表）
    //函数指针 or 函数的返回值是指针
    //eg:
    //int(*pf)(int);
    //int* p(int); 返回值是int*的函数  p
    //char *strcpy    
    

    return 0;
}