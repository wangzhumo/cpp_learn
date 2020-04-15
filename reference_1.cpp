#include <iostream>
#include <assert.h>

using namespace std;

void swap1(int a,int b){
    int temp = a;
    a = b;
    b = temp;
}

void swap2(int& a,int& b){
    int temp = a;
    a = b;
    b = temp;
}


void swap3(int* a,int* b){
    int temp = *a;   //保存a值 的地址
    *a = *b;
    *b = temp;      //把a值得地址设置给 *b ,这样b的值就是 a值了
}


//引用
//  是一种特殊的指针,不允许修改指针指向的指针
//  - 不存在空引用
//  - 必须初始化
//  - 一个引用永远指向他初始化的那个对象


//
int main(){
    int x =1, y = 3;

    int &x1 = x;

    cout << x << endl;
    cout << x1 << endl;
   //x1就相当于是x的别名

    x1 = y;
    cout << x << endl;   //这里可以发现,x 的值成了 3,也就是说,x1 = y 就是  x = y;
    cout << x1 << endl;


    int a = 3,b = 4;
    //swap1(a,b);     //Assertion `a == 4 && b == 3' failed.
    //swap2(a,b);    // ok
    swap3(&a,&b);    // ok
    assert(a == 4 && b == 3);


    return 0;
}