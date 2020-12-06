//
// Created by wangzhumo on 2020/12/6.
//

#include "../../includes/leetcode/move_zeroes.h"

// 把一段带0的序列中的0全部移动到尾部
void MoveZeroes::moveZeroes(std::vector<int> &nums) {
    // 创建一个新的序列
    std::vector<int> vec;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i]) {
            vec.push_back(nums[i]);
        }
    }
    // 把序列补全
    int size = vec.size();
    for (int j = 0; j < nums.size(); j++) {
        if (j >= size) {
            nums[j] = 0;
        } else {
            nums[j] = vec[j];
        }
    }
}


// 双指针
// 就是说 0 的位置可以随意占用
// fastIndex 遍历整个序列
// slowIndex 代表排序后的序列
void MoveZeroes::moveZeroesDoubleIndex(std::vector<int> &nums) {
    int slowIndex =0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i]){
            nums[slowIndex] = nums[i];
            slowIndex++;
        }
    }
    // 而后补零即可
    for (int j = slowIndex; j < nums.size(); j++) {
        nums[j] = 0;
    }
}


