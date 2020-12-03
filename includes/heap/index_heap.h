//
// Created by wangzhumo on 2020/12/3.
//

#ifndef LEARN_CPP_INDEX_HEAP_H
#define LEARN_CPP_INDEX_HEAP_H

#include <iostream>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <cmath>

/**
 * 索引堆
 * 1.利于查找
 * 2.排序只是排序索引的位置，性能好
 */
template<class Item>
class IndexHeap {
private:
    Item *data;  //数据
    int count;   //当前个数
    int capacity; //容量
    int *indexes; // 索引的数组
public:
    explicit IndexHeap(int capacity);

    IndexHeap(Item arr[],int capacity);

    ~IndexHeap();

    // 当前容量
    int size() { return count; }

    // 是否为空
    bool isEmpty() { return count == 0; }

    /**
     * 添加元素
     * @param index
     * @param e
     *
     * 传入的index是数组中的位置，从0开始
     */
    void insert(int index,Item e);

    // 获取一个元素
    Item pop();
};


#endif //LEARN_CPP_INDEX_HEAP_H
