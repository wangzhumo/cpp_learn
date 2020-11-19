//
// Created by 王诛魔 on 2020-11-18.
//

#include "../../../includes/sorts/quick_sort.h"


// 找到一个key
// 即整个序列保证一定满足
// arr[left,j-1]  <  key < [j+1,right]
template<typename T>
T _partition(T *arr, int left, int right) {
    //** 优化
    // 针对近乎有序的序列，我们取一个随机的key
    std::swap(arr[left], arr[(rand() % (right - left + 1)) + left]);

    // 先找到一个参照值(随机)
    T key = arr[left];

    // 定义key当前的位置 index
    int j = left;

    // 循环，开始排序
    // 因为left位置是参考值，所以直接从left+1开始搞起
    for (int i = left + 1; i <= right; i++) {
        // 开始比较
        if (key > arr[i]) {
            // 如果大于，那么应该交换位置，
            // 也就是把当前考察的这个元素和 key 交换位置
            // i 是当前比较的位置
            // j+1 的话，
            std::swap(arr[i], arr[j + 1]);
            // 此时j的位置应该移动了一个
            j++;
        }
    }
    // 循环完毕之后，需要把key自己移动到j的最后一位
    std::swap(arr[j], arr[left]);
    return j;
}


// 找到一个key
// 即整个序列保证一定满足
// arr[left,j-1]  <  key < [j+1,right]
template<typename T>
T _partitionDouble(T *arr, int left, int right) {
    //** 优化
    // 针对近乎有序的序列，我们取一个随机的key
    std::swap(arr[left], arr[(rand() % (right - left + 1)) + left]);

    // 先找到一个参照值(随机)
    T key = arr[left];

    // 一个是左侧开始，加1避开key的位置
    int i = left + 1;
    // 一个是右侧开始
    int j = right;

    while (true) {
        while (i <= right && arr[i] < key) {
            // 此时满足小于key,不需要移动，只增加i即可
            i++;
        }
        while (j > left && arr[j] > key) {
            j--;
        }
        // 如果i > j 说明已经相遇，不需要继续
        if (i > j) break;
        // 交换位置即可,因为i 以及 j 现在都指向的是已经拍好序的下一个元素
        // 因此直接交换即可
        std::swap(arr[i], arr[j]);
        // 这里交换完毕之后，应该让比较的对象向下移动一次
        i++;
        j--;
    }
    // 此时我们需要把key的位置放到正确的地方
    std::swap(arr[left], arr[j]);
    return j;
}


// 使用递归使得  排序的序列不断减小，每一段都排序
// 一直排序到 left >= right 说明已经无法再细分了，即整个序列都排序完成

// 快速排序在近乎有序的序列中
// 另一侧的序列几乎没有，一直在计算左侧的序列，会退化为 n*n

// 快速排序在有大量重复元素的序列中，也可能会把整个序列分为几个不平衡的序列
// 会退化为 n*n
template<typename T>
void _quickSort(T *arr, int left, int right) {
    // 一个退出的条件
    if (left >= right) {
        return;
    }
    // 先找到一个比较的对象
    int keyIndex = _partition(arr, left, right);
    _quickSort(arr, left, keyIndex - 1);
    _quickSort(arr, keyIndex + 1, right);
}

template<typename T>
void _quickSortDouble(T *arr, int left, int right) {
    // 一个退出的条件
    if (left >= right) {
        return;
    }
    // 先找到一个比较的对象
    int keyIndex = _partitionDouble(arr, left, right);
    _quickSortDouble(arr, left, keyIndex - 1);
    _quickSortDouble(arr, keyIndex + 1, right);
}


template<class T>
void QuickSort<T>::quickSort(T *arr, int number) {
    _quickSort(arr, 0, number - 1);
}

template<class T>
void QuickSort<T>::quickSortDouble(T *arr, int number) {
    srand(time(NULL));
    _quickSortDouble(arr, 0, number - 1);
}


// Explicit template instantiation
template
class QuickSort<int>;