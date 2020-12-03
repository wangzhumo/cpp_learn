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

template<class Item>
void IndexHeap<Item>::shiftUp(int index) {
    // 添加新的元素
    // 一直比较，直到自己小于父元素
    while (index > 1 && data[index / 2] < data[index]) {
        //如果自己大于了父元素，那么交换位置，在索引堆中交换index即可
        std::swap(data[index], data[index / 2]);
        // 修改当前位置
        index /= 2;
    }
}


// Explicit template instantiation
template
class IndexHeap<int>;

