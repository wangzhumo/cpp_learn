//
// Created by wangzhumo on 2020/7/25.
//

#include "../../includes/advance/observable.h"

Observable::Observable():_value(0) {

}


Observable::~Observable() {

}

// 添加一个观察
void Observable::addListener(Observer *pObserve) {
    if (pObserve == NULL){
        return;
    }
    // 类型推断
    auto it = _observerList.begin();
    // 遍历
    for(;it != _observerList.end();it++){
        // 是否已经添加
        if(*it == pObserve){
            return;
        }
    }
    _observerList.push_back(pObserve);
}

// 移除
void Observable::removeListener(Observer* pObserver) {
    if (pObserver == NULL || _observerList.empty()){
        return;
    }
    _observerList.remove(pObserver);
}

void Observable::setChange(std::string value) {
    _value = 1;
    // 转为char*  再强转为 void*
    notifyChange((void*)value.c_str());
}

void Observable::notifyChange(void *pObserve) {
    //通知观察者们更新数据了
    if (_value == 0){
        return;
    }
    // 遍历，更新数据
    auto it = _observerList.begin();
    for (;it != _observerList.end();it++){
        (*it)->update(pObserve);
    }
    _value = 0;
}
