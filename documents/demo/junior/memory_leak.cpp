#include <iostream>
#include <memory>
#include <string>

using namespace std;

//内存泄露
//  程序中已经动态分配的堆内存由于一些原因没有释放,或者无法释放
//  造成系统的内存浪费,导致程序运行速度减慢,甚至程序异常崩溃等后果.
//
//智能指针
//	unique_ptr
//	shared_ptr
//	weak_ptr
//	(deprecated) auto_ptr   C++17
//		- 通过 new  获取对象,在auto_ptr对象销毁的时候,他所管理的对象也会自动delete
//		- 如果传递给其他的智能指针,原来的指针就失去了控制权,会被置为null_ptr
//		

int main(){

    {
        //大括号用来确定auto_ptr的失效范围
        auto_ptr<int> pl(new int(10));

        cout << *p1 << endl;


        auto_ptr<string> code_lang[5] = {
            auto_ptr<string>(new string("C++")),
            auto_ptr<string>(new string("Kotlin")),
            auto_ptr<string>(new string("Java")),
            auto_ptr<string>(new string("Python")),
            auto_ptr<string>(new string("Rust"))
        };

        auto_ptr<string>  pC;
        pC = code_lang[2];
        //此时,code_lang中的元素, java 就已经被释放了,已经成为了nullptr,而pC获得了原来的值

    }
    //当超出这个 {} 的范围后,auto_ptr会自己释放,从而使得它指向的对象也会释放 delete/
    return 0;
}
