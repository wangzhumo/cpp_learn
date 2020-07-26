//
// Created by wangzhumo on 2020/7/26.
//
#include <vector>
#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>

struct Display{
    void operator()(int i){
        std::cout << i << " ";
    }
};

// for_each
void printCollection(int array[]){
    // vector / list / deque 的使用
    std::vector<int> _iVector(array,array+4);
    std::list<int> _iList(array,array+4);
    std::deque<int> _iDeque(array, array + 4);
    std::queue<int> _iQueue(_iDeque);
    std::stack<int> _iStack(_iDeque);
    std::priority_queue<int> _iPriorityQueue(array,array+4);

    std::for_each(_iVector.begin(),_iVector.end(),Display());
    std::cout << std::endl;
    std::for_each(_iList.begin(),_iList.end(),Display());
    std::cout << std::endl;
    std::for_each(_iDeque.begin(),_iDeque.end(),Display());

    std::cout << std::endl;
    while (!_iQueue.empty()) {
        // 不为空就继续遍历
        std::cout << _iQueue.front() << " ";
        _iQueue.pop();
    }

    std::cout << std::endl;

    while (!_iStack.empty()) {
        // 不为空就继续遍历
        std::cout << _iStack.top() << " ";
        _iStack.pop();
    }

    std::cout << std::endl;
    while (!_iStack.empty()) {
        // 不为空就继续遍历
        std::cout << _iStack.top() << " ";
        _iStack.pop();
    }
    
}

