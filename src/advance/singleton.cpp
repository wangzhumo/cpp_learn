//
// Created by wangzhumo on 2020/7/25.
//

#include "../../includes/advance/singleton.h"

Singleton::Singleton() {

}

Singleton::~Singleton() {

}

Singleton* Singleton::instance = NULL;

// 如果这样，当程序加载的时候就会去调用它的构造
// Singleton* Singleton::instance = new Singleton();


const Singleton *Singleton::getInstance() {
    // 判断实例
    if (!instance){
        instance = new Singleton();
    }
    return instance;
}

void Singleton::sayHello() {
    std::cout << "Hello Singleton" << std::endl;
}


//   Singleton::getInstance()->sayHello();