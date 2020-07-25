//
// Created by wangzhumo on 2020/7/25.
//
// 适配器模式
//   复用老代码
//   扩充功能
#include <iostream>
#include <string>

class LegacyRect{
public:
    LegacyRect(double l,double t,double r,double b){
        _l = l;
        _t = t;
        _r = r;
        _b = b;

        std::cout << "RectAdapter1" << std::endl;
    }

    void legacyDraw(){
        std::cout << "LegacyRect Draw....." << std::endl;
    }

private:
    double _l;
    double _t;
    double _r;
    double _b;
};


// 定义一个 -- 类似于接口的东西，执行这个函数
class RectBase{
public:
    virtual void draw(std::string str) = 0;
};

// 适配器模式 一 使用多重继承
class RectAdapter1: public RectBase, private LegacyRect{
public:
    // 在这里我们对 LegacyRect 进行实例化
    RectAdapter1(int l,int t,int r,int b) : LegacyRect(l,t,r,b + 1){
       std::cout << "RectAdapter1" << std::endl;
    }

    void draw(std::string str) override{
        std::cout << "RectAdapter1 draw, " << str << std::endl;
        // do something
        std::cout << "RectAdapter1 draw, do something" << std::endl;
        // call LegacyRect
        legacyDraw();
    }

//    int main() {
//        // 实例化一个Adapter
//        RectAdapter1 adapter1(1,2,3,4);
//        RectBase* rect = &adapter1;
//        rect->draw("TEST Adapter1");
//        return 0;
//    }
//            RectAdapter1
//            RectAdapter1
//            RectAdapter1 draw, TEST Adapter1
//            RectAdapter1 draw, do something
//            LegacyRect Draw.....
};


// 适配器模式 二  组合
class RectAdapterCon: public RectBase{
public:
    // 在这里我们对 LegacyRect 进行实例化
    RectAdapterCon(double l,double t,double r,double b) : _legacyRect(l,t,r,b + 1){
        std::cout << "RectAdapter2" << std::endl;
    }

    void draw(std::string str) override{
        std::cout << "RectAdapter2 draw, " << str << std::endl;
        // do something
        std::cout << "RectAdapter2 draw, do something" << std::endl;
        // call LegacyRect
        _legacyRect.legacyDraw();
    }

private:
    LegacyRect _legacyRect;



//    int main() {
//        // 实例化一个Adapter
//        RectAdapterCon adapter1(1,2,3,4);
//        RectBase* rect = &adapter1;
//        rect->draw("TEST Adapter1");
//        return 0;
//    }
//            RectAdapter1
//            RectAdapter2
//            RectAdapter2 draw, TEST Adapter1
//            RectAdapter2 draw, do something
//            LegacyRect Draw.....


};