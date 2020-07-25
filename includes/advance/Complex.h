//
// Created by wangzhumo on 2020/7/25.
//

#ifndef CPP_LEARN_COMPLEX_H
#define CPP_LEARN_COMPLEX_H

#pragma once
#include <iostream>

class Complex{
public:
    Complex();
    // 构造函数
    Complex(double r,double i);
    // 析构函数
    virtual ~Complex();

    double getReal() const {
        return _real;
    }

    double getImage() const {
        return _image;
    }

    void setReal(double realValue){
        _real = realValue;
    }

    void setImage(double imageValue){
        _image = imageValue;
    }

    // 运算符重载

    //operator 重载操作符
    //+   重载+号
    //const 左边没有，看右边   修饰  Complex&

    // 参数为引用，不需要重复创建空间，而且这个引用的值不可以修改
    Complex operator+ (const Complex& x);

    // 前置操作符
    Complex& operator++ ();

    // 后置操作符  int 用于区别前置和后置
    Complex operator++ (int);

    // friend  定义这个成员，在 类的外部（不是继承啊什么的）也可以调用
    friend std::ostream& operator<<(std::ostream& os,const Complex& complex);
    // 输入的值可能需要改变，去掉 const .
    friend std::istream& operator>>(std::istream& is,Complex& complex);
private:
    double _real;
    double _image;
};

#endif //CPP_LEARN_COMPLEX_H