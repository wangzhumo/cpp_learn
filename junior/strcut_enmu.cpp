#include <iostream>

using namespace std;

//使用 #define 以及 const 创建常量

//枚举
// 定义新的数据类型，还可以创建常量
// 指定可选的参数
int main()
{

    enum COLORS
    {
        GREEN,
        GRAY,
        BLUE,
        BLACK,
        RED
    };

    COLORS colo;
    colo = BLACK;
    cout << colo << endl;
    return 0;
}