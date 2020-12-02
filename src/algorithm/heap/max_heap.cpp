//
// Created by 王诛魔 on 12/2/20.
//

#include "../../../includes/heap/max_heap.h"

template<class Item>
MaxHeap<Item>::MaxHeap(int capacity) {
    // 初始化开辟的元素个数
    data = new Item[capacity + 1];
    count = 0;
}

template<class Item>
MaxHeap<Item>::~MaxHeap() {
    // 删除数据
    delete[] data;
}