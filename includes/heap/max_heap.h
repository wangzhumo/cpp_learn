//
// Created by 王诛魔 on 12/2/20.
//

#ifndef LEARN_CPP_MAX_HEAP_H
#define LEARN_CPP_MAX_HEAP_H

template<class Item>
class MaxHeap {
private:
    Item *data;  //数据
    int count;   //当前个数
public:
    MaxHeap(int capacity);

    ~MaxHeap();

    // 当前容量
    int size() { return count; }

    // 是否为空
    bool isEmpty() { return count == 0; }
};

#endif  // LEARN_CPP_MAX_HEAP_H
