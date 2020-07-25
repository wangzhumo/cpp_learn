//
// Created by wangzhumo on 2020/7/25.
//

#ifndef CPP_LEARN_SINGLETON_H
#define CPP_LEARN_SINGLETON_H

#endif //CPP_LEARN_SINGLETON_H
#include <iostream>

class Singleton{

public:
    static const Singleton* getInstance();

    static void sayHello();

private:
    // 不允许外部直接构造自己的实例
    Singleton();
    ~Singleton();

    // 希望它不会跟随这个实例的销毁而销毁
    // 所以我们不能把它放在栈里
    // static 静态变量  --  随着整个程序而存在
    static Singleton* instance;

};