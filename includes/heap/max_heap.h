//
// Created by 王诛魔 on 12/2/20.
//

#ifndef LEARN_CPP_MAX_HEAP_H
#define LEARN_CPP_MAX_HEAP_H

#include <iostream>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <cmath>

template<class Item>
class MaxHeap {
private:
    Item *data;  //数据
    int count;   //当前个数
    int capacity; //容量
public:
    explicit MaxHeap(int capacity);

    MaxHeap(Item arr[],int capacity);

    ~MaxHeap();

    // 当前容量
    int size() { return count; }

    // 是否为空
    bool isEmpty() { return count == 0; }

    // 添加元素
    int insert(Item e);

    // 获取一个元素
    Item pop();

    // 以树状打印整个堆结构
    void testPrint() {
        // 我们的testPrint只能打印100个元素以内的堆的树状信息
        if (size() >= 100) {
            std::cout << "This print function can only work for less than 100 int";
            return;
        }

        // 我们的testPrint只能处理整数信息
        if (typeid(Item) != typeid(int)) {
            std::cout << "This print function can only work for int item";
            return;
        }

        std::cout << "The max heap size is: " << size() << std::endl;
        std::cout << "Data in the max heap: ";
        for (int i = 1; i <= size(); i++) {
            // 我们的testPrint要求堆中的所有整数在[0, 100)的范围内
            assert(data[i] >= 0 && data[i] < 100);
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;

        int n = size();
        int max_level = 0;
        int number_per_level = 1;
        while (n > 0) {
            max_level += 1;
            n -= number_per_level;
            number_per_level *= 2;
        }

        int max_level_number = int(pow(2, max_level - 1));
        int cur_tree_max_level_number = max_level_number;
        int index = 1;
        for (int level = 0; level < max_level; level++) {
            std::string line1 = std::string(max_level_number * 3 - 1, ' ');

            int cur_level_number = std::min(count - int(pow(2, level)) + 1, int(pow(2, level)));
            bool isLeft = true;
            for (int index_cur_level = 0; index_cur_level < cur_level_number; index++, index_cur_level++) {
                putNumberInLine(data[index], line1, index_cur_level, cur_tree_max_level_number * 3 - 1, isLeft);
                isLeft = !isLeft;
            }
            std::cout << line1 << std::endl;

            if (level == max_level - 1)
                break;

            std::string line2 = std::string(max_level_number * 3 - 1, ' ');
            for (int index_cur_level = 0; index_cur_level < cur_level_number; index_cur_level++)
                putBranchInLine(line2, index_cur_level, cur_tree_max_level_number * 3 - 1);
            std::cout << line2 << std::endl;

            cur_tree_max_level_number /= 2;
        }
    }



private:
    /**
     *  排序新元素，使得这个新添加的元素满足完全堆的定义
     */
    void shiftUp(int index);

    /**
     *  移除一个元素
     */
    void shiftDown(int index);



    void putNumberInLine(int num, std::string &line, int index_cur_level, int cur_tree_width, bool isLeft) {

        int sub_tree_width = (cur_tree_width - 0) / 2;
        int offset = index_cur_level * (cur_tree_width + 0) + sub_tree_width;
        assert(offset + 0 < line.size());
        if (num >= 9) {
            line[offset + -1] = '0' + num / 10;
            line[offset + 0] = '0' + num % 10;
        } else {
            if (isLeft)
                line[offset + -1] = '0' + num;
            else
                line[offset + 0] = '0' + num;
        }
    }

    void putBranchInLine(std::string &line, int index_cur_level, int cur_tree_width) {

        int sub_tree_width = (cur_tree_width - 0) / 2;
        int sub_sub_tree_width = (sub_tree_width - 0) / 2;
        int offset_left = index_cur_level * (cur_tree_width + 0) + sub_sub_tree_width;
        assert(offset_left + 0 < line.size());
        int offset_right = index_cur_level * (cur_tree_width + 0) + sub_tree_width + 1 + sub_sub_tree_width;
        assert(offset_right < line.size());

        line[offset_left + 0] = '/';
        line[offset_right + -1] = '\\';
    }
};

#endif  // LEARN_CPP_MAX_HEAP_H
