//
// Created by 王诛魔 on 12/2/20.
//

#include "../../../includes/heap/max_heap.h"


/**
 * 其中如果从０开始构建一个堆
 * parent(i) = (i-1)/2
 * left child(i) = 2 * i + 1
 * right child(i) = 2 * i +２
 * 最后一个堆就是: (count - 1) /2
 *
 *
 * 如果是从1开始的
 * parent(i) = i/2
 * left child(i) = 2 * i
 * right child(i) = 2 * i +1
 * 最后一个堆就是: count /2
 */

template<class Item>
MaxHeap<Item>::MaxHeap(int capacity) {
    // 初始化开辟的元素个数
    data = new Item[capacity + 1];
    count = 0;
    this->capacity = capacity;
}

template<class Item>
MaxHeap<Item>::MaxHeap(Item *arr, int capacity) {
    data = new Item[capacity + 1];
    this->capacity = capacity;
    for (int i = 0; i < capacity; i++) {
        data[i+1] = arr[i];
    }
    count = capacity;
    // 此时我们还需要对这个heap进行排序.
    // 也就是找到最后一个堆(capacity / 2)，开始排序，一直排序到1
    for (int j = capacity/2; j >= 1; j--) {
        shiftDown(j);
    }
}


template<class Item>
MaxHeap<Item>::~MaxHeap() {
    // 删除数据
    delete[] data;
}

template<class Item>
int MaxHeap<Item>::insert(Item e) {
    assert(capacity > (count+1));
    data[count+1] = e;
    count++;
    shiftUp(count);
    return count;
}

// 一个新元素,自下而上的比较
template<class Item>
void MaxHeap<Item>::shiftUp(int index) {
    // 添加新的元素
    // 一直比较，直到自己小于父元素
    while (index > 1 && data[index / 2] < data[index]) {
        //如果自己大于了父元素，那么交换位置
        std::swap(data[index], data[index / 2]);
        // 修改当前位置
        index /= 2;
    }
}

// 已经移除的顶点，此时顶点的元素不满足最大堆
// 需要自上而下的移动
template<class Item>
void MaxHeap<Item>::shiftDown(int index) {
    // 比较即可,如果左边没有元素，说明就没有子元素了。
    while (index*2 <= count){
        int k = 2*index; //当前要比较的子元素
        if (k+1 < count && data[k+1] > data[k]){
            // 如果有右边的元素，找出两个子元素的最大值
            k+=1;
        }
        // 此时再进行比较
        if (data[index] < data[k]){
            // 如果自己比子元素小，则应该交换位置
            std::swap(data[index] , data[k]);
        }else{
            // 否则退出循环
            break;
        }
        index = k;
    }
}

// 取出最大值
template<class Item>
Item MaxHeap<Item>::pop() {
    assert(count > 0);
    Item item = data[1]; // 因为添加的时候，是从1开始添加的
    // 把最后一个元素移动到第一个
    std::swap(data[1],data[count]);
    // count--
    count--;
    // 重新排序
    shiftDown(1);
    return item;
}



// Explicit template instantiation
template
class MaxHeap<int>;

template
class MaxHeap<float>;