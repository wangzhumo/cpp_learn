//
// Created by wangzhumo on 2020/7/25.
//
#include "../../includes/advance/Complex.h"
#include <iostream>

Complex::Complex() {
    _real = 0.0;
    _image = 0.0;
    std::cout << "Complex::Complex()" << std::endl;
}

Complex::Complex(double r,double i){
    _real = r;
    _image = i;
    std::cout << "Complex::Complex(double r,double i)" << std::endl;
}

Complex::~Complex(){
    std::cout << "Complex::~Complex" << std::endl;
}

// 操作符
Complex Complex::operator+(const Complex& x){
    Complex temp;
    temp._real = _real + x._real;
    temp._image = _image + x._image;
    return temp;
}

// 前置操作符
Complex& Complex::operator++() {
    _real++;
    _image++;
    return *this;
}

// 后置操作符
Complex Complex::operator++(int) {
    //首先创建一个临时操作符
    Complex temp(*this);
    _real++;
    _image++;
    return temp;
}


// 重载了标准IO - 输出
// 这个方方法，是一个全局的方法，不仅仅只属于 Complex 类自己
std::ostream& operator<<(std::ostream &os, const Complex &complex){
    os << "real Value is " << complex._real << " ,image Value is " << complex._image;
    return os;
}


// 重载标准IO - 输入
std::istream& operator>>(std::istream &is, Complex &complex){
    is >> complex._image >> complex._real;
    return is;
}


//int main() {
//    std::cout << "Hello, World!" << std::endl;
//    Complex c(1.0,2.0);
//    Complex b(3.0, 1.0);

//    Complex complex;
//    complex = c++;
//    std::cout << "complex++ & = " << &complex << std::endl;
//    complex = ++c;
//    std::cout << "++complex & = " << &complex << std::endl;

    // complex++ & = 0x7ffcb7c01650
    // ++complex & = 0x7ffcb7c01650

//    complex = ++c;
//    std::cout << "++complex & = " << &complex << std::endl;
//    complex = c++;
//    std::cout << "complex++ & = " << &complex << std::endl;

//    std::cin >> complex;
//    std::cout << complex << std::endl;

//    Hello, World!
//            Complex::Complex()
//    2.0 3.8
//    2.0 3.8
//    real Value is 3.8 ,image Value is 2
//    return 0;
//}