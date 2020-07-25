#include "Complex.h"
#include "iostream"

Complex::Complex(){
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