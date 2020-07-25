//
// Created by wangzhumo on 2020/7/25.
//

#ifndef CPP_LEARN_OBSERVERABLE_H
#define CPP_LEARN_OBSERVERABLE_H

#include <list>
#include <string>
#include "observer.h"

class Observable{
public:
    Observable();
    virtual ~Observable();

    virtual void doSomeThing(std::string news){
        //默认是更改数据
        setChange(news);
    }

    // 提供一个add / remove / clear 的方法
    void addListener(Observer* pObserve);
    // remove
    void removeListener(Observer* pObserver);
    // 清除
    void clearListener(){
        _observerList.clear();
    }
protected:
    // 子类去调用
    void setChange(std::string value);

private:
    int _value;

    std::list<Observer*> _observerList;

    // 只允许被观察者自己去调用
    void notifyChange(void* pObserve);

};


#endif //CPP_LEARN_OBSERVERABLE_H
