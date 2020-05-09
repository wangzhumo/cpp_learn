#include <iostream>


// 斐波那锲数列最简单的递归调用
int fib_origin(int num)
{
    if (num == 0)
    {
        return 0;
    }
    if (num == 1)
    {
        return 1;
    }
    return fib_origin(num - 1) + fib_origin(num - 2);
}

// 递归实现
//  - 递归的思想
//  - 缺陷1 ： 对于空间上需要较大的开销
//  - 缺陷2 ： 可能在某些步骤上会大量的重复，时间上会有浪费

//  - 递归的优化
//  - 优化1 ： 尾递归，所有的递归形式的调用最好在函数的末尾
//  - 优化2 ： 循环替代
//  - 优化3 ： 动态优化，时间换取空间
int main()
{

    return 0;
}