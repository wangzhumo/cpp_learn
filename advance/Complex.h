//定义一个类
#pragma once

class Complex
{
public:
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
    
private:
    double _real;
    double _image;

};