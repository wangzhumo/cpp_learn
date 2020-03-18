#include <iostream>

using namespace std;

//指针的基本运算
// & 取地址
// * 取一个指针指向地址的值
int mian(){

    char ch = 'a';
    // &操作符

    // &ch = 97;       // &ch左值不合法
    char* cp = &ch;    // &ch右值,取出地址
    // &cp = 97;       // &cp左值不合法
    char** cpp = &cp;  // &cp右值 

    // *操作符
    *cp = 'a';         // *cp左值取变量ch位置
    char ch2 = *cp;    // *cp右值取ch存储的值
    // *cp + 1 = 'a';  // 不合法的位置
    ch2 = *cp + 1;     // 这样就是 a + 1 也就是 ASCII码加一
    *(cp + 1) = 'a';   // 地址加上了1
    ch2 = *(cp + 1);   // 取地址加一后的值


    *cp++ = 98;    //这样的话,会先 (*cp) 取到cp里面的值,然后给cp
                   //最后,cp自增,也就是说,cp指针的地址自增了


    return 0;
}