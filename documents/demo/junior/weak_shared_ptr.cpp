#include <iostream>
#include <memory>

using namespace std;

//shared_ptr(获取所有权)
//  通过一个引用计数来管理一个对象,当引用了一个对象就给他的引用计数 加 1
//  如果这个引用计数为 0 ,说明已经没用人去使用它了,此时释放这个对象.

//循环引用
//  两个对象中,互相引用的对方的对象,这两个对象就永远不能释放了.

//weak_ptr(只是去使用,并不需要所有权)
//  被设计用来与shared_ptr共同工作,观察者模式,当shared_ptr失效后相应的weak_ptr也会失效
//  shared_ptr p1
//  weak_ptr w1 ( p1 )  此时w1只是获取了p1 并且使用它,但是p1的指向对象引用计数并不会增加

int main(){

    //shared_ptr 代表共享这个所有权,多个shared_ptr共享同一个内存
    auto wA = std::shared_ptr<int>(new int(20));

    {
        auto wA2 = wA;
        //输出
        cout << ((wA2.get() != nullptr) ? (*wA2.get()) : -1) << endl;  //20
        cout << ((wA.get() != nullptr) ? (*wA.get()) : -1) << endl;  //20
        cout << wA2.use_count() << endl;    //2
        cout << wA.use_count() << endl;     //2
    } 

    //当use_count()    
    cout << wA.use_count() << endl; 
    cout << ((wA.get() != nullptr) ? (*wA.get()) : -1) << endl;  //20

    //当wA2离开了作用域之后,就没有引用计数了
    cout << ((wA.get() != nullptr) ? (wA.use_count()) : -1) << endl; //1 


    //move 语法 shared_ptr 
    auto wAA = std::shared_ptr<int>(new int(30));
    auto wAA2 = std::move(wAA);
    //此时wAA放弃了对这个对象的管理,wAA = nullptr ,而wAA2获取了wAA原来的对象
    cout << ((wAA.get() != nullptr) ? (*wAA.get()) : -1) << endl;  //-1
    cout << ((wAA2.get() != nullptr) ? (*wAA2.get()) : -1) << endl;  //30
    cout << wAA.use_count() << endl;    //0
    cout << wAA2.use_count() << endl;     //1

    return 0;
}