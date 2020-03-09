#include <iostream>
#include <string>

using namespace std;

//String的基本操作.
//注意去使用 strnlen_s  stcpy_s 等等的安全函数
//redis.io   sdshdr  它类似于Java中的ArrayList，它采用预分配冗余空间的方式来减少内存的频繁分配

int main(){

    char hellow[] = {"hello ~world!"};


    //1.长度  strlen() 字符串的有效长度
    //      sizeof()  字符串的空间占用长度
    for (int i = 0; i < strlen(hellow); i++)
    {
        /* code */
    }
    cout << "字符创的有效长度: " << strlen(hellow) << endl;
    cout << "字符创的空间占用: " << sizeof(hellow) << endl;

    //2.比较 strcmp(s1,s2) ASCII
    //s1 == s2  return 0   
    //s1 < s2  return <0
    //s1 > s2  return >0

    //3.复制 strcpy(s1,s2)  strncpy(s1,s2,n)  把s2中的0-n个字符复制到s1中
    //       strcpy_s

    //4.字符串拼接  strcat(s1,s2)  字符串s2拼接到s1后面

    //5.查找字符串  strchr(s1,char1)查找一个字符   strstr(s1,s2)查找string

    return 0;
}
