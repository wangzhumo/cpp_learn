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
    // 几种不同的inset写法
    studentSocres["LiMing"] = 95.0;
    studentSocres["LiHong"] = 98.5;
    studentSocres.insert(std::pair<std::string, double>("zhangsan", 100.0));
    studentSocres.insert(std::pair<std::string, double>("Lisi", 98.6));
    studentSocres.insert(std::pair<std::string, double>("wangwu", 94.5));
    studentSocres.insert(std::map<std::string, double>::value_type("zhaoliu", 95.5));
    // 覆盖之前的 wangwu
    studentSocres["wangwu"] = 88.5;

    // 打印
    std::for_each(studentSocres.begin(), studentSocres.end(), Display2());


    // 查找一个key
    std::map<std::string,double>::iterator iter;
    iter = studentSocres.find("zhangsan");
    if (iter != studentSocres.end()) {
        std::cout << "Find Key,value = " << iter->second << std::endl;
    }else{
        std::cout << "Did't find key" << std::endl;
    }

    // 遍历的方式查找   过滤大于95 的
    iter = studentSocres.begin();
    while (iter != studentSocres.end()) {
        if (iter->second < 95.0) {
            // 如果小于95就删除掉，这样剩下的就是大于95的了
            // erase 后，当前的这个迭代器位置就失效了
            // erase 会返回下一个位置，可以接受它
            iter = studentSocres.erase(iter);
            // 如果上面没有接受新的iter,那么在这了就需要移动
            // 就算是删除了，也要记得把迭代器先前移动

            //iter++;
        }else{
            // 移动
            iter++;
        }
    }
    // 看看是否找到了
    std::for_each(studentSocres.begin(), studentSocres.end(), Display2());


}

