//
// Created by wangzhumo on 2020/7/27.
//

#ifndef LEARN_CPP_STL_FUNCTOR_H
#define LEARN_CPP_STL_FUNCTOR_H

#include <algorithm>
#include <iostream>

bool MyCompare(int a, int b) {
    return a > b;
}

template<class T>
inline bool MyCompare2(T a, T b) {
    return a > b;
}

void Display(int a) {
    std::cout << a << " ";
}

template<class T>
inline void Display2(T a) {
    std::cout << a << " ";
}

// cpp仿函数模板
template<class T>
struct SortF {
    inline bool operator()(T const &a, T const &b) const {
        return a > b;
    }
};

template<class T>
struct DisplayF {
    inline void operator()(T const &a) const {
        std::cout << a << " ";
    }
};


void sortLikeCpp(int array[]) {
    std::sort(array, array + 4, MyCompare);
    std::for_each(array, array + 4, Display);
    std::cout << std::endl;
}

void sortTemplate(int array[]) {
    std::sort(array, array + 4, MyCompare2<int>);
    std::for_each(array, array + 4, Display2<int>);
    std::cout << std::endl;
}

void sortFunctorTemplate(int array[]) {
    std::sort(array, array + 4, SortF<int>());
    std::for_each(array, array + 4, DisplayF<int>());
    std::cout << std::endl;
}


#endif //LEARN_CPP_STL_FUNCTOR_H
