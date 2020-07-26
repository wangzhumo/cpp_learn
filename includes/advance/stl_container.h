//
// Created by wangzhumo on 2020/7/26.
//

#ifndef LEARN_CPP_STL_CONTAINER_H
#define LEARN_CPP_STL_CONTAINER_H


#include <vector>
#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>

#include <map>
#include <string>

struct Display {
    void operator()(int i) {
        std::cout << i << " ";
    }
};

struct Display2{
    void operator()(std::pair<std::string, double> info){
        std::cout << info.first << ": " << info.second << std::endl;
    }
};


void printCollection(int array[]);

void printMap();

#endif //LEARN_CPP_STL_CONTAINER_H
