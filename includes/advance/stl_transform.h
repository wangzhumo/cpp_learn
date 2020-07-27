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

// 使用递归，查找所有的排列组合
// 这里使用的思路就是，首先确定第一个元素，然后递归确定其他的元素
void findAllNumber(char* pStr,char* position){
    std::cout << "参数 ：" << pStr << " ," << position <<  std::endl;
    // 退出的条件
    if (*position == '\0'){
        std::cout << pStr << std::endl;
    }else{
        for (char* pChar = position;*pChar != '\0';pChar++){
            // 意思是，先把开始的问题赋值给开始的索引
            // 而后一直循环到这个子列表的结尾
            std::swap(*pChar,*position);
            // 接续查找后面的组合
            findAllNumber(pStr,position+1);
            // 交换回来
            std::swap(*pChar, *position);
        }
    }

}
#endif //LEARN_CPP_STL_TRANSFORM_H
