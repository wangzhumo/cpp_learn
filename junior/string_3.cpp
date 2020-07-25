#include <iostream>
#include <string.h>

using namespace std;


//string数据结构
// #include <string>
// using namespace std;
// 更加的方便以及安全
int main(){
    string s;   //声明后赋值

    string s1 = "hellow world";  //直接赋值

    string s2 = "hello world 2";

    string s4 = ("hello world3");

    string s3 = string("hello world4");
    
    //获取长度 length()  size()  capacity()
    cout<< "字符串长度 length" << s1.length() << endl;
    cout<< "字符串 size =" << s1.size() << endl;
    cout<< "字符串长度 capacity = " << s1.capacity() << endl;


    //c  与  c++  的转换
    //1.直接使用 c_str
    const char* strChar = s1.c_str();
    //2.拷贝  +1 为了  /0
    char * strc = new char[strlen(s1.c_str())+1];
    strcpy(strc, s1.c_str());    

    //strcpy_s   系列是Window自己的实现

    //拷贝
    string cp_s2 = s1;

    //拼接
    string append_s1 = cp_s2 + s3;

    return 0;
}