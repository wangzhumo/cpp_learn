//
// Created by wangzhumo on 2020/7/25.
//

#include "../../includes/advance/observer.h"
#include "../../includes/advance/observable.h"
#include <iostream>

class User1: public Observer{
    void update(void* pArg) override{
        std::cout << "User1 update : " << (char*)pArg << std::endl;
    }

};

class User2: public Observer{
    void update(void* pArg) override{
        std::cout << "User2 update : " << (char*)pArg << std::endl;
    }
};


// 被观察者对象
class News: public Observable{
public:
    void getSomeNews(std::string str){
        setChange("News -> " + str);
    }
};
