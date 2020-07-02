#include "Complex.h"
#include "iostream"

Complex::Complex(double r,double i){
    _real = r;
    _image = i;
    std::cout << "Complex::Complex" << std::endl;
}

Complex::~Complex(){
    std::cout << "Complex::~Complex" << std::endl;
}