//定义一个类
#pragma once

class Complex
{
public:
    Complex();
    Complex(double r,double i);  // 构造函数
    virtual ~Complex();  // 析构函数

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

private:
    double _real;
    double _image;

};