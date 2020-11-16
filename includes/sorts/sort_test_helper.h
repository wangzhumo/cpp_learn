//
// Created by 王诛魔 on 2020-11-16.
//

#ifndef LEARN_CPP_SORT_TEST_HELPER_H
#define LEARN_CPP_SORT_TEST_HELPER_H

#include <iostream>
#include <ctime>
#include <cassert>

namespace SortTestHelper {

    // 产生随机数
    int *generateRandomArray(int n, int start, int limit) {
        assert(start <= limit);
        int *arr = new int[n];
        //set random seed
        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % (limit - start + 1) + start;
        }
        return arr;
    }

    // 产生随机数
    int *generateNearlyOrderArray(int n, int swapTimes) {
        int *arr = new int[n];
        //set random seed
        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }
        for (int j = 0; j < swapTimes; ++j) {
            int posX = rand() % n;
            int posY = rand() % n;
            std::swap(arr[posX], arr[posY]);
        }
        return arr;
    }

    int *copyIntArray(int aArr[], int n) {
        // 拷贝
        int *arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = aArr[i];
        }
        return arr;
    }


    // 打印
    template<typename T>
    void printArray(T arr[], int n) {
        for (int i = 0; i < n; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    // 是否大小顺序
    template<typename T>
    bool isSorted(T arr[], int n) {
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        return true;
    }

    // 测试
    template<typename T>
    void testSort(std::string sortName, void(*sort)(T[], int), T arr[], int n) {
        std::clock_t startTime = clock();
        sort(arr, n);
        std::clock_t endTime = clock();

        // 是否排序成功的？
        assert(isSorted(arr, n));
        std::cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << std::endl;
    }

}


#endif //LEARN_CPP_SORT_TEST_HELPER_H
