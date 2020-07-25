#include <iostream>

using namespace std;


//指针
//https://zhuanlan.zhihu.com/p/27974028
//这“两己三他”，展开来说，就是：己址、己值、他值、他址、他型
//
//
//左值   
//  单独分配的存储空间,可以取到这个空间的地址,通常放在赋值运算符的左侧
//  eg : 常见的有函数和数据成员
//右值
//  指的是数据本身,没有单独的空间,不能取到它的地址,只能在赋值运算符的右侧
//  eg : 没有标识符,不可以取地址的表达式,一般称为 "临时变量"
//  a = b + c
//      &a是可以取到地址的,但是 &(c + b) 就是错误的操作
//      a 就是一个左值,(b + c)就是一个右值
//
//
//指针的数组    -   数组的指针
// T* t[]          T(*t) []
// int* a[4]       int(*b)[4]
int main(){
    int a = 112,b = -1;

    float c = 3.14F;

    int* d = &a;

    float* e = &c;

    cout << a << endl;   //112
    cout << (&a) << endl;   //0x7ffee0fa3f6c
    cout << b << endl;   //-1
    cout << c << endl;   //3.14
    cout << (*d) << endl;    //112
    cout << (d) << endl;    //0x7ffeea823f6c
    cout << (&d) << endl;    //0x7ffeea823f58
    cout << e << endl;  //0x7ffee0e2df64


    int a1[4] = {3,6,9,7};
    int* a2[4];
    int(*b1)[4];
    b1 = &a1;  //需要保证数组的个数一致

    //赋值
    for (unsigned int i = 0; i < 4; i++)
    {
       a2[i] = &(a1[i]);
    }
    
    cout << *a2[0] << endl;
    cout << (*b1)[3] << endl;  // *b1 就是数组了
    return 0;
}