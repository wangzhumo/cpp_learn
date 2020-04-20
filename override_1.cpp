#include <iostream>

using namespace std;


//函数重载 与 C++的 Name Mangling
int test(int a);

int test(double a);

int test(int a ,int b);
// ?test@@YAHH@Z
// ?test@@YAHN@Z
// ?test@@YAHHN@Z




//override
int main(){

    return 0;
}