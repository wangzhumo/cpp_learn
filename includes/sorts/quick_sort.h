//
// Created by 王诛魔 on 2020-11-18.
//

#ifndef LEARN_CPP_QUICK_SORT_H
#define LEARN_CPP_QUICK_SORT_H


#include <iostream>
#include <ctime>
// 使用模板函数
template<typename T>
class QuickSort{
public:
    QuickSort() = default;
    ~QuickSort() = default;

    void quickSort(T arr[], int number);
    void quickSortDouble(T arr[], int number);
};


#endif //LEARN_CPP_QUICK_SORT_H
