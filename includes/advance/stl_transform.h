//
// Created by wangzhumo on 2020/7/27.
//

#ifndef LEARN_CPP_STL_TRANSFORM_H
#define LEARN_CPP_STL_TRANSFORM_H

#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>

// transform
// lambda 表达式
// [外部传入的参数](自己的参数)->返回值的类型 { 要执行的语句 }
void printTransform(int array[], int array2[], int result[]) {
    std::transform(array, array + 4, array2, result, std::plus<int>());
    // 上面相加，结果在result
    std::for_each(result, result + 4, [](int a) -> void {
        std::cout << a << std::endl;
    });
}

void findNumberCount() {
    int numbers[] = {2,3,4,3,4,2,11,21,32,21,32,4,51,11};
    std::cout << sizeof(numbers) << std::endl;
    std::cout << sizeof(numbers[0]) << std::endl;

    // 11 的个数
    auto result = std::count(numbers, numbers + (sizeof(numbers) / sizeof(numbers[0])), 11);
    std::cout << result << std::endl;

    // 小于20的个数
    auto result1 = std::count_if(numbers, numbers + (sizeof(numbers) / sizeof(numbers[0])),
            std::bind2nd(std::less<int>(),20));
    std::cout << result1 << std::endl;

    // 大于20的个数
    auto result2 = std::count_if(numbers, numbers + (sizeof(numbers) / sizeof(numbers[0])),
                                 std::bind1st(std::less<int>(),20));
    std::cout << result2 << std::endl;
}

#endif //LEARN_CPP_STL_TRANSFORM_H
