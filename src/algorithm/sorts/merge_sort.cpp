//
// Created by 王诛魔 on 2020-11-17.
//

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
    _merge(arr, left, mid, right);
}

// 归并排序.
template<class T>
void MergeSort<T>::mergeSort(T arr[], int number) {
    _mergeSort(arr, 0, number - 1);
}


// Explicit template instantiation
template class MergeSort<int>;