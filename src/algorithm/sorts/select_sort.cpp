//
// Created by 王诛魔 on 2020-11-16.
//

#include "../../../includes/sorts/select_sort.h"

// SelectSort
template <class T>
void SelectionSort<T>::selectionSort(T arr[], int number) {
    for (int i = 0; i < number;i++) {
        // [i,n) 最小值的位置
        int minValueIndex = i;
        // 查找[i+1,n)位置中比自己还小的值。
        for (int index = i+1;index < number;index ++){
            if (arr[index] < arr[minValueIndex]){
                minValueIndex = index;
            }
        }
        // 完事了之后，交换位置。
        std::swap(arr[i],arr[minValueIndex]);
    }
    // 完毕
}


// Explicit template instantiation
template class SelectionSort<int>;