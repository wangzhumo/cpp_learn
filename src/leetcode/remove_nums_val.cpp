//
// Created by wangzhumo on 2020/12/7.
//

#include "../../includes/leetcode/remove_nums_val.h"


//示例 2:
//给定 nums = [0,1,2,2,3,0,4,2], val = 2,
// i = 循环
// k = 等于k的地方
//

//函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。
//
//注意这五个元素可为任意顺序。
//
//你不需要考虑数组中超出新长度后面的元素。
int RemoveNumsVal::removeElement(std::vector<int>& nums, int val) {
    // 遍历整个数组
    int k = 0;  // k the last order list index
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val){
            if (i > k){
                std::swap(nums[k],nums[i]);
            }
            k++;
            std::cout << "i = " << i << " , k = " << k << std::endl;
            
        }else{
            
            //k++;  // 此时等待下一个
            std::cout << "k = " << k << std::endl;
        }
    }
    return k;
}