//
// Created by wangzhumo on 2020/12/7.
//

#ifndef LEARN_CPP_REMOVE_NUMS_VAL_H
#define LEARN_CPP_REMOVE_NUMS_VAL_H

#include <vector>

//给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
//不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
//
//元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/remove-element
class RemoveNumsVal {
public:
    int removeElement(std::vector<int>& nums, int val);
};


#endif //LEARN_CPP_REMOVE_NUMS_VAL_H
