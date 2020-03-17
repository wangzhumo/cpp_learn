#include <iostream>

using namespace std;

//const pointer 以及 pointer to const
//
//1.看左侧最近的部分
//2.如果左侧没有就看右侧
//
//
//未初始化和非法的指针
//eg: int *a
//    *a = 12;
// - 定位到一个非法的地址,程序会直接出错,终止运行
// - 定位到一个随机的地址,然后去操作了它(无法发现,无法追踪)        
//
//
//野指针
//指向"垃圾"的内存指针
// - 指针没有初始化
// - 已经释放不用的指针没有置为NULL,如delete和 free之后的指针
// - 指针操作超越了变量的作用范围(越界了,超越生命周期的指针引用)
int main(){
    char strHw[] = {"hello world."};

    char const *pStr1 = "hello world";       //表示指针是可以改的,但是当前指向的那片区域不可以修改
    //同 const char* pStr1 = "hello world";

    char* const pStr2 = strHw;       //指针不可以改变,就是说指向不能修改,但是可以去修改当前指向的空间的值

    char const * const pStr3 = "hello world";       //指针的指向以及指向的内容也是不可以修改的.

    //pStr1 = strHw;  //ok
    //pStr2 = strHw;  //不可改变
    //pStr3 = strHw   //不可改变
    return 0;
}