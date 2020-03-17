#include <iostream>

using namespace std;


//指针
int main(){
    int a = 112,b = -1;

    float c = 3.14F;

    int* d = &a;

    float* e = &c;

    cout << a << endl;   //112
    cout << (&a) << endl;   //0x7ffee0fa3f6c
    cout << b << endl;   //-1
    cout << c << endl;   //3.14
    cout << (*d) << endl;    //112
    cout << (d) << endl;    //0x7ffeea823f6c
    cout << (&d) << endl;    //0x7ffeea823f58
    cout << e << endl;  //0x7ffee0e2df64

    return 0;
}