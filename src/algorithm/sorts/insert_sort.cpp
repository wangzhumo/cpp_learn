//
// Created by 王诛魔 on 2020-11-16.
//

#include "../../../includes/sorts/insert_sort.h"


// 普通的插入排序 - swap
template<class T>
void InsertionSort<T>::insertionSort(T arr[], int number) {
    // 0 的位置无法比较，自己就是最小的,直接1开始
    for (int i = 1; i < number; i++) {
        // 寻找比自己小的位置插入,只需要先前比较即可
        // 保证自己是已经拍好序中最小的即可
        for (int j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1]) {
                std::swap(arr[j], arr[j - 1]);
            } else {
                //否则自己已经比前面一个元素大，
                break;
            }
        }
    }
}

// 减少位置交换的插入排序
template<class T>
void InsertionSort<T>::insertionSortDecSwap(T arr[], int number){
    for (int i = 1; i < number; i++) {
        // 先把自己保存起来
        T currentValue = arr[i];
        int j;
        for (j = i; j > 0; j--) {
            // 如果自己小于前面一个元素，把前面一个元素赋值给自己
            if (currentValue < arr[j - 1]) {
                arr[j] = arr[j-1];
            } else {
                break;
            }
        }
        // 最后,把自己放到指定的位置
        // 这样的话，减少了swap的使用
        arr[j] = currentValue;
    }
}

// Explicit template instantiation
template class InsertionSort<int>;