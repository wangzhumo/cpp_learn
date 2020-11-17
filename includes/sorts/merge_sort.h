//
// Created by 王诛魔 on 2020-11-17.
//

#ifndef LEARN_CPP_MERGE_SORT_H
#define LEARN_CPP_MERGE_SORT_H
// 使用模板函数
template<typename T>
class MergeSort{
public:
    MergeSort() = default;
    ~MergeSort() = default;

    void mergeSort(T arr[], int number);
};

#endif //LEARN_CPP_MERGE_SORT_H
