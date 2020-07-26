//
// Created by wangzhumo on 2020/7/26.
//
#include "../../includes/advance/stl_container.h"

// 序列式容器
// for_each
void printCollection(int array[]) {
    // vector / list / deque 的使用
    std::vector<int> _iVector(array, array + 4);
    std::list<int> _iList(array, array + 4);
    std::deque<int> _iDeque(array, array + 4);
    std::queue<int> _iQueue(_iDeque);
    std::stack<int> _iStack(_iDeque);
    std::priority_queue<int> _iPriorityQueue(array, array + 4);

    std::for_each(_iVector.begin(), _iVector.end(), Display());
    std::cout << std::endl;
    std::for_each(_iList.begin(), _iList.end(), Display());
    std::cout << std::endl;
    std::for_each(_iDeque.begin(), _iDeque.end(), Display());

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

    while (!_iPriorityQueue.empty()) {
        // 不为空就继续遍历
        std::cout << _iPriorityQueue.top() << " ";
        _iPriorityQueue.pop();
    }

    std::cout << std::endl;

}


void printMap() {
    std::map<std::string, double> studentSocres;
    studentSocres["LiMing"] = 95.0;
    studentSocres["LiHong"] = 98.5;
    studentSocres.insert(std::pair<std::string, double>("zhangsan", 100.0));
    studentSocres.insert(std::pair<std::string, double>("Lisi", 98.6));
    studentSocres.insert(std::pair<std::string, double>("wangwu", 94.5));
    studentSocres.insert(std::map<std::string, double>::value_type("zhaoliu", 95.5));
    studentSocres["wangwu"] = 88.5;

    // 打印
    std::for_each(studentSocres.begin(), studentSocres.end(), Display2());

}

