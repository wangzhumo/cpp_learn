//
// Created by wangzhumo on 2020/7/25.
//

#ifndef CPP_LEARN_OBSERVER_H
#define CPP_LEARN_OBSERVER_H

class Observer{
public:
    Observer(){;}
    virtual ~Observer(){;}


    // 当观察对象发生变化，被观察者调用这个方法
    virtual void update(void* pArg) = 0;
};


#endif //CPP_LEARN_OBSERVER_H
