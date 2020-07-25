//
// Created by wangzhumo on 2020/7/25.
//
// 使用泛型，重写一个大小比较的方法

#include <string.h>

class GenericType{
public:
    template<class T> T max(T a,T b){
        return a > b ? a:b;
    }

    // 特化
    char* max(char* a,char* b){
        return strcmp(a,b) == 0 ? (a) : (b);
    }

    // 可以确定返回值，但不知参数
    template<class T,class E> int max(T t,E e){
        return t > e ? t : e;
    }

//    int main() {
//        GenericType type;
//        std::cout <<   type.max(12.9,12.1) << std::endl;
//
//        char* a = "hello";
//        char* b = "height";
//        std::cout <<  type.max(a,b) << std::endl;
//
//        std::cout <<  type.max(11,12.9) << std::endl;
//        //12.9
//        //height
//        //12
//        return 0;
//    }



    // what ???
    template<int n> struct Sum{
        enum Value {N = Sum<n-1>::N+n};
    };

    template<> struct Sum<1>{
        enum Value{N =1};
    };

    // std::cout << Sum<100>::N << endl;
};