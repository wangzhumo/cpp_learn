//
// Created by wangzhumo on 2020/12/3.
//

#include "../../../includes/heap/index_heap.h"


template<class Item>
IndexHeap<Item>::IndexHeap(int capacity) {
    // 初始化开辟的元素个数
    data = new Item[capacity + 1];
    indexes = new int[capacity + 1];
    count = 0;
    this->capacity = capacity;
}

template<class Item>
IndexHeap<Item>::~IndexHeap<Item>() {
    delete data;
    delete indexes;
}


template<class Item>
void IndexHeap<Item>::insert(int index, Item e) {
    assert((count + 1) < capacity);   //容量检查
    assert((index + 1) > 1 && (index + 1) < capacity);  // 越界检查
    index+=1;  // 对应到堆，需要加上1
    data[index] = e;  // 数据的序列直接放置到对应的位置即可
    indexes[count+1] = index;
    count++;
}

// Explicit template instantiation
template
class IndexHeap<int>;

