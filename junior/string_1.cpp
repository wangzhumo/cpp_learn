#include <iostream>
#include <vector>

using namespace std;

// 字符串以空字符( /0 )结束的字符数组 
// 没有字节序的问题
// UTF-8    1byte标识字符,长度可变.存储效率高,但是因为可变,不能随机访问

// 以下两种,定长方便随机访问,但是都有字节序的问题
// UTF-16   2byte   UTF-16BE(big endian)
//                  UTF-16LE(little endian)
// UTF-32   3byte   UTF-32BE(big endian)
//                  UTF-32LE(little endian)

//Window文件有BOM(byte order mark) 的特殊标记符号
int main() {
    char helloworld[] = {"helloworld"};

    char helloStr[11] = {"helloworld"}; 

    char* pHelloStr = "helloworld";

    cout<< helloworld << endl;
    cout<< helloStr << endl;


    for (int i = 0; i < 10; i++)
    {
        /* code */
        helloStr[i] += 1;
        cout << helloStr[i] << endl;
    }

    //Error 
//    for (int i = 0; i < 10; i++)
//     {
//         /* code */
//         pHelloStr[i] += 1;
//         cout <<pHelloStr[i] << endl;
//     } 

    //ok.
    pHelloStr = helloStr;
    for (int i = 0; i < 10; i++)
    {
        /* code */
        pHelloStr[i] += 1;
        cout <<pHelloStr[i] << endl;
    } 

    //以上 helloStr 的值不可以再次赋值,但是helloStr中的值可以改变
    // pHelloStr 的值可以改变,其中保存的值是否可以改变,需要看这个保存的值
    return 0;
}