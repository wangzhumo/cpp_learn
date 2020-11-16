//
// Created by 王诛魔 on 2020-11-16.
//

#ifndef LEARN_CPP_INSERT_SORT_H
#define LEARN_CPP_INSERT_SORT_H


#include <iostream>

template<typename T>
// 使用模板函数
class InsertionSort{
public:
    InsertionSort() = default;
    ~InsertionSort() = default;

    void insertionSort(T arr[], int number);

    void insertionSortDecSwap(T arr[], int number);
};

#endif //LEARN_CPP_INSERT_SORT_H
