//
// Created by 王诛魔 on 2020-11-16.
//

#ifndef LEARN_CPP_SORT_TEST_HELPER_H
#define LEARN_CPP_SORT_TEST_HELPER_H

#include <iostream>
#include <ctime>
#include <cassert>

namespace SortTestHelper{
    // 产生随机数
    int* generateRandomArray(int n,int start,int limit){
        assert(start<limit);
        int *arr = new int[n];
        //set random seed
        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % (limit - start + 1) + start;
        }
        return arr;
    }

    // 打印
    template<typename  T>
    void printArray(T arr[],int n){
        for (int i = 0; i < n; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

}


#endif //LEARN_CPP_SORT_TEST_HELPER_H
