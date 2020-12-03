//
// Created by wangzhumo on 2020/12/3.
//

#include "../../../includes/heap/index_heap.h"

template<class Item>
IndexHeap<Item>::IndexHeap(int capacity) {
    // 初始化开辟的元素个数
    data = new Item[capacity + 1];
    indexes = new int[capacity + 1];
    reverse = new int[capacity + 1];
    for (int i = 0; i <= capacity; i++) {
        // 这里reverse指向0,是为了标记data中这个元素在堆中是没有记录的
        reverse[i] = 0;
    }
    count = 0;
    this->capacity = capacity;
}

template<class Item>
IndexHeap<Item>::~IndexHeap<Item>() {
    delete data;
    delete indexes;
    delete reverse;
}

template<class Item>
void IndexHeap<Item>::shiftUp(int index) {
    // 添加新的元素
    // 一直比较，直到自己小于父元素,此时的index对应的是indexes中的索引
    // 对应的data中index是 indexes
    while (index > 1 && data[indexes[index / 2]] < data[indexes[index]]) {
        //如果自己大于了父元素，在索引堆中交换index即可
        std::swap(indexes[index], indexes[index / 2]);
        // indexes 中的值交换了位置，相应的reverse中值也需要重新赋值
        // 就是说 indexes 中index位置的值变化了
        // reverse[indexes[index]] = index
        // 就变成了原来 reverse[indexes[index/2]] = index
        // 此时我们的index是不会变化的,通过变化后的indexes表示：
        //  那么 reverse[indexes[index/2]] = index
        //  那么 reverse[indexes[index]] = index/2
        // 以为修改了值，它的值发生了变化，此时需要交换reverse的值
        reverse[indexes[index]] = index;
        reverse[indexes[index / 2]] = index / 2;

        // 修改当前位置
        index /= 2;
    }
}

template<class Item>
void IndexHeap<Item>::shiftDown(int index) {
    while (index * 2 <= count) {
        int k = 2 * index;  //当前要比较的子元素
        if (k + 1 < count && data[indexes[k + 1]] > data[indexes[k]]) {
            // 如果有右边的元素，找出两个子元素的最大值
            k += 1;
        }
        // 此时再进行比较
        if (data[indexes[index]] < data[indexes[k]]) {
            // 如果自己比子元素小，则应该交换位置
            std::swap(indexes[index], indexes[k]);
            // 这里和shiftUp里面的道理一致，就是交换reverse的位置。
            // 但是因为indexes已经先交换过了，所以原来的
            // reverse[indexes[k]] = index;
            // 就需要变为 reverse[indexes[index]] = index;
            reverse[indexes[index]] = index;
            reverse[indexes[k]] = k;
        } else {
            // 否则退出循环
            break;
        }
        index = k;
    }
}

template<class Item>
void IndexHeap<Item>::insert(int index, Item e) {
    assert((count + 1) <= capacity);                     //容量检查
    assert((index + 1) >= 1 && (index + 1) <= capacity);  // 越界检查

    // 再插入一个新元素前,还需要保证索引i所在的位置是没有元素的。
    assert(!contain(index));

    // 外部传入的index是从0开始的，对应到堆，需要加上1
    index += 1;
    // 数据的序列直接放置到对应的位置即可
    data[index] = e;
    indexes[count + 1] = index;
    // 此时我们需要把这个count+1记录下来
    reverse[index] = count + 1;
    count++;
    // shiftUp即可
    shiftUp(count);
}

template<class Item>
Item IndexHeap<Item>::getItem(int index) {
    return data[index + 1];
}

template<class Item>
Item IndexHeap<Item>::pop() {
    assert(count > 0);
    // indexes 中的第一个元素，对应的就是堆中第一个元素的值
    Item item = data[indexes[1]];

    // 把最后一个索引元素移动到第一个
    std::swap(data[indexes[1]], data[indexes[count]]);
    // 这就意味着，把之前indexes[1]的这个元素置为1
    reverse[indexes[1]] = 1;
    // 把这个已经没有用处的地方，置为0
    reverse[indexes[count]] = 0;

    // count--
    count--;
    // 重新排序
    shiftDown(1);
    return item;
}

template<class Item>
int IndexHeap<Item>::popIndex() {
    assert(count > 0);
    // indexes 中的第一个元素，对应的就是堆中第一个元素的值
    int itemIndex = indexes[1];
    // 我们在保存的时候，保存的是index+=1的值
    // 所以外部使用的话，也应该 -1
    itemIndex -= 1;

    // 把最后一个索引元素移动到第一个
    std::swap(data[indexes[1]], data[indexes[count]]);
    // 把这个已经没有用处的地方，置为0
    reverse[indexes[count]] = 0;
    // count--
    count--;
    if (count){
        // 这就意味着，把之前indexes[1]的这个元素置为1
        reverse[indexes[1]] = 1;
        // 重新排序
        shiftDown(1);
    }
    return itemIndex;
}

template<class Item>
void IndexHeap<Item>::update(int index, Item item) {
    // 如果不存在，会直接退回
    assert(contain(index));
    // 首先把index+1,得到在堆中的位置
    index += 1;
    // 赋值给data
    data[index] = item;
    // 重新排序,这个新的值在堆中现在的位置，通过reverse就可以直接拿到
    int heapIndex = reverse[index];
    // 排序即可
    shiftUp(heapIndex);
    shiftDown(heapIndex);
}

// Explicit template instantiation
template
class IndexHeap<int>;
