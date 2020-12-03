//
// Created by wangzhumo on 2020/12/3.
//

#ifndef LEARN_CPP_INDEX_HEAP_H
#define LEARN_CPP_INDEX_HEAP_H

#include <algorithm>
#include <cassert>
#include <cmath>
#include <ctime>
#include <iostream>
#include <string>

/**
 * 索引堆
 * 1.利于查找
 * 2.排序只是排序索引的位置，性能好
 *
 * reverse[i] = j; 也就是说这个data位置的元素被排序后在堆中（indexes）的位置是j
 * indexes[j] = i; 那么直接取indexes[i]的位置，取到的就是data中元素的位置 i
 *
 * 其中i指的是元素在data中的索引值：
 *
 * reverse[i] 取到的是i这个位置元素，被排列到堆(indexes)中的哪一个位置
 * 因此，indexes[堆中这个元素的index值在indexes的位置]
 * 就应该对应着这个元素的index
 *
 * indexes[reverse[i]] = i;
 * reverse[indexes[i]] = i;
 */
template <class Item>
class IndexHeap {
   private:
    Item* data;  //数据，此时的data并不是一个堆，仅仅是原始数据
    int count;     //当前个数
    int capacity;  //容量
    // 索引的数组，它可以看做是一个堆，
    // 只不过他需要通过data获取到堆元素

    // 其中保存的是 堆中这个元素的index值
    int* indexes;

    // 可以通过data的index快速的获取它在indexes中的index
    // 其中保存的是 元素index的值保存在在indexes中的那个位置
    int* reverse;

   public:
    explicit IndexHeap(int capacity);

    ~IndexHeap();

    // 当前容量
    int size() { return count; }

    // 是否为空
    bool isEmpty() { return count == 0; }

    // 是否在堆中
    bool contain(int index) {
        assert(index + 1 <= capacity && index + 1 >= 1);
        return reverse[index + 1] != 0;
    }

    /**
     * 添加元素
     * @param index
     * @param e
     *
     * 传入的index是数组中的位置，从0开始
     */
    void insert(int index, Item e);

    // 获取最大元素
    Item pop();

    // 获取最大元素的index
    int popIndex();

    // 获取在指定位置的元素(原始序列)
    Item getItem(int index);

    // 修改指定位置元素
    void update(int index, Item item);

   private:
    /**
     *  排序新元素，使得这个新添加的元素满足完全堆的定义
     */
    void shiftUp(int index);

    /**
     *  移除一个元素
     */
    void shiftDown(int index);
};

#endif  // LEARN_CPP_INDEX_HEAP_H
