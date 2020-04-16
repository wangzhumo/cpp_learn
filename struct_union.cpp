#include <iostream>

using namespace std;


//联合体
//当多个数据需要共享内存或者多个数据每次只取其一时，可以利用联合体(union)。在C Programming Language 一书中对于联合体是这么描述的：
//1)联合体是一个结构；
//2)它的所有成员相对于基地址的偏移量都为0；
//3)此结构空间要大到足够容纳最"宽"的成员；
//4)其对齐方式要适合其中所有的成员；

//内存中数据低位字节存入低地址，高位字节存入高地址，而数据的地址采用它的低地址来表示
union Score
{
    double sc;
    char level;
};



union U1
{
	int n;
	char s[11];
	double d;
};

//对于U1联合体，s占11字节，n占4字节，d占8字节，因此其至少需1字节的空间。
//然而其实际大小并不是11，用运算符sizeof测试其大小为16。
//这是因为这里存在字节对齐的问题，11既不能被4整除，也不能被8整除。
//因此补充字节到16，这样就符合所有成员的自身对齐了。
//从这里可以看出联合体所占的空间不仅取决于最宽成员，还跟所有成员有关系，即其大小必须满足两个条件：
// 1)大小足够容纳最宽的成员；
// 2)大小能被其包含的所有基本数据类型的大小所整除。


//结构体
//结构体的数据对齐问题
//在系统中，把4bit作为一个整体
//char 1bit 但是在内存中还是4bit一块


//最大原则
//一个结构体中，会考虑最大的元素内存大小，一般是  最大元素最为基本单位 * 元素个数
struct Student
{
    char name[6];   //6
    int age;        //4
    Score score;    //8

    //但是因为最大原则，就成了 8 * 3 = 24
};



//doucment/strcut_memory_4k.png

int main(){
  cout << sizeof(double) << endl;  
  cout << sizeof(Score) << endl; //8     
  cout << sizeof(Student) << endl; //24
}