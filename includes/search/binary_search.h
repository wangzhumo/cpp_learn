//
// Created by 王诛魔 on 12/3/20.
//

#ifndef LEARN_CPP_BINARY_SEARCH_H
#define LEARN_CPP_BINARY_SEARCH_H

template<typename T>
class BinarySearch {

public:
    BinarySearch() = default;

    ~BinarySearch() = default;

    int binarySearch(T arr[], int n, T target);
};

#endif //LEARN_CPP_BINARY_SEARCH_H
