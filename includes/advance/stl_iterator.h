//
// Created by wangzhumo on 2020/7/27.
//

#ifndef LEARN_CPP_STL_ITERATOR_H
#define LEARN_CPP_STL_ITERATOR_H

#include <list>
#include <iostream>
#include <algorithm>

using namespace std;
// 正向迭代器   iterator
// 常量迭代器   const_iterator  也就是说，这个迭代器的元素不可以修改它
// 反向迭代器   reverse_iterator
// 反向常量迭代器    const_reverse_iterator

void printListWithIterator(){
    list<int> l;
    l.push_front(3);
    l.push_front(2);
    l.push_front(1);
    l.push_back(4);
    l.push_back(5);

    // 通过迭代器遍历
    list<int>::const_iterator it;
    for (it = l.begin();it != l.end();it++){
        cout << *it << " ";
    }

    cout << endl;

    // 顶部pop
    l.pop_front();
    //[外部传入的参数](自己的参数)->返回值的类型 { 要执行的语句 }
    for_each(l.begin(),l.end(),[](int& x)->void {cout<< x << " ";});
}


#endif //LEARN_CPP_STL_ITERATOR_H
