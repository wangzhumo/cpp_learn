//
// Created by 王诛魔 on 2020-11-17.
//

#include <algorithm>
#include <iostream>
#include "../../../includes/sorts/merge_sort.h"


// 归并排序.[left,mid]  [mid+1,right] 两个部分进行合并
template<typename T>
void _merge(T *arr, int left, int mid, int right) {
    // 这里需要一个副本
    T tempArr[right - left + 1];
    // 这里需要注意的是，i需要等于right.
    for (int i = left; i <= right; i++) {
        // 这里tempArr index是从0开始的
        // 而arr作为原始数组，应该是left开始
        tempArr[i - left] = arr[i];
    }

    // 此时我们可以开始归并了
    int i = left;   // 左边数组开头的位置
    int j = mid + 1;   // 右边数组开头的位置
    for (int k = left; k <= right; k++) {
        // 此时开始比较
        if (i > mid) {
            // 这样操作的原因是，这两个数组自己是有序的
            arr[k] = tempArr[j - left];
            j++;
        } else if (j > right) {
            arr[k] = tempArr[i - left];
            i++;
        } else if (tempArr[i - left] < tempArr[j - left]) {
            // 此时修改原始数组k这个位置的数据
            arr[k] = tempArr[i - left];
            // 赋值完毕，我们的i需要先前走一步
            i++;
        } else {
            arr[k] = tempArr[j - left];
            j++;
        }
    }
}

// 归并排序需要使用递归，做一个私有方式
// 对 [left,right]中间的数据进行排序
template<typename T>
void _mergeSort(T *arr, int left, int right) {
    // 退出条件，分解到最后无法继续拆分为止，只有一个或者0个元素
    if (left >= right) {
        return;
    }
    // 获取中间值
    int mid = (right - left) / 2 + left;
    // 此时排序 [left,mid]  [mid+1,right]
    _mergeSort(arr, left, mid);
    _mergeSort(arr, mid + 1, right);

    // ###优化
    // 保[left,mid]中的最大值
    // 是大于[mid+1,right]的最小值的，否则是不需要进行归并的
    if (arr[mid] > arr[mid + 1]) {
        _merge(arr, left, mid, right);
    }

}

// 归并排序.
template<class T>
void MergeSort<T>::mergeSort(T arr[], int number) {
    _mergeSort(arr, 0, number - 1);
}


// 归并排序 for 循环，不需要额外的空间
// 对 [0,number-1]中间的数据进行排序
template<typename T>
void _mergeSortBU(T *arr, int number) {
    // 每次对两个数组进行遍历,最小也应该是都是一个元素的集合比较
    for (int size = 1; size < number; size += size) {
        std::cout << "Size : " << size << std::endl;
        // [0]  [1]
        // [0,1] [2,3]
        // [0,3] [4,7]
        // 这里的for循环，为了计算出每次的merge开始位置
        for (int i = 0; i < number; i += (2 * size)) {
            std::cout << "left : " << i << "  mid : " << (i + size - 1)
                      << "  right : " << std::min(i + (size * 2) - 1,number-1) << std::endl;

            // 合并之前的两个集合
            // arr[i,i+size-1]  arr[i+size,i+2*size-1]
            _merge(arr, i, i + size - 1, std::min(i + (size * 2) - 1,number-1));
        }
    }

    // 第一个for 循环，是为了给出每一个子集合的个数，而且这个数组的个数会逐渐的增加
    // 一直到这个size = number/2  1,2,4,8,...number/2

    // 第二个for 循环，是为了根据上一步的集合内部容量计算出每段集合的开头位置.
    // 即分割出number/size 个集合出来，merge后变成 number/size/2 个有序的集合
    // eg: size = 1
    //     这样的话，会把整个原始集合中的元素，相邻的两个进行merge，
    //     结果[0,1] [2,3] 就变成有序的序列了
    //
    //     size = 2
    //     会把 [0,1] [2,3]   [4,5] [6,7]....... [n-1,n] 两两merge
    //     结果[0,3] [4,7] .. 就变成有序了
    //
    //     size = 4
    //     [0,3] [4,7]  ...
    //     结果[0,7] [8,15] 就变成有序了
    //
    //     快进到size = number/2
    //     [0,number/2-1]  [number/2,number]  merge之后，整个集合就有序了

}

template<class T>
void MergeSort<T>::mergeSortBU(T arr[], int number) {
    _mergeSortBU(arr, number);
}

// Explicit template instantiation
template
class MergeSort<int>;