#include <iostream>

using namespace std;

// 斐波那锲数列最简单的递归调用
int fib_origin(int num)
{
    if (num == 0)
    {
        return 0;
    }
    else if (num == 1)
    {
        return 1;
    }
    else
    {
        return fib_origin(num - 1) + fib_origin(num - 2);
    }
}

// 使用循环替代递归
int fib_for(int num)
{
    //如果小于2，直接返回
    if (num < 2)
    {
        return num;
    }

    // 此时我们需要把递归调用展开
    int n0 = 0, n1 = 1;
    int temp;
    // 因为小于2 已经被直接返回了，所以应该从2开始
    // 每一次循环都计算出当前位置的数字，这样一直向前计算
    // 直到我们需要的位置，循环停止

    // 我们每一次计算出来的新值，因为是属性变量而被保存起来，避免了再次计算它的问题
    for (int i = 2; i <= num; i++)
    {
        // 此时计算,把第一位数字保存起来
        temp = n0;
        // 第一位数据向前赋值
        n0 = n1;
        // 计算出新的第二位数据 (旧第二位数 + 旧第一位数字)
        n1 = n1 + temp;
        cout << n1 << endl;
    }
    return n1;
}

// 递归实现
//  - 递归的思想
//  - 缺陷1 ： 对于空间上需要较大的开销
//  - 缺陷2 ： 可能在某些步骤上会大量的重复，时间上会有浪费

//  - 递归的优化
//  - 优化1 ： 尾递归，所有的递归形式的调用最好在函数的末尾
//  - 优化2 ： 循环替代
//  - 优化3 ： 动态优化，空间换取时间
int main()
{
    cout << fib_origin(9) << endl;
    cout << fib_for(9) << endl;
    return 0;
}