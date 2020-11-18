//
// Created by 王诛魔 on 2020-11-18.
//

#ifndef LEARN_CPP_QUICK_SORT_H
#define LEARN_CPP_QUICK_SORT_H


#include <iostream>

template<typename T>
// 使用模板函数
class QuickSort{
public:
    QuickSort() = default;
    ~QuickSort() = default;

    void quickSort(T arr[], int number);
};


#endif //LEARN_CPP_QUICK_SORT_H
