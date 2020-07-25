//
// Created by wangzhumo on 2020/7/25.
//

// 强制类型转换

// C 的类型转换
//   隐式类型转换
//      eg:  double f = 10/2;
//   显示类型转换
//      eg:  double f = double(1) / double(2)
//   问题 :
//     1.任意类型都可以转换，编译器无法判断
//     2.难以定位


// C++ 的类型转换
//   const_cast  一般用于指针或者引用，去掉const属性
//   reinterpret_cast  危险，重新解释类型，要求内存大小要一致
//   static_cast  类似c中的基本类型转换，以及对有继承关系对象和指针之间的转换
//   dynamic_cast  只能用于含有虚函数的类，必须在多态体系中，（如果检查非法，就返回NULL）
class CastCpp{
public:
    static void castCppEg(){
         const int a = 10;
         //int* pA = &a;  //error: invalid conversion from const int*  to int
         int* pA = const_cast<int*>(&a);
         // 尝试去改变它
         *pA = 100;
    }


};