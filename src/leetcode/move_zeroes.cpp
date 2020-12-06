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
        if (j > size) {
            nums[j] = 0;
        } else {
            nums[j] = vec[j];
        }
    }
}
