#include <iostream>

using namespace std;

//内联函数
//空间换时间的方式，可以提高效率

//如果一个函数是内联函数，那么在编译的时候，编译器会把这个
//函数的代码副本直接放在每一个调用这个函数的地方
//从而不用去处理汇编中的位移，复制等等

//内联函数，直接加 inline 即可
inline int maxNum(int a, int b)
{
    return a >= b ? a : b;
}

int main()
{
    ///递归函数，复杂的判断都不适合使用内联函数。
    cout << maxNum(10, 12) << endl;

    return 0;
}