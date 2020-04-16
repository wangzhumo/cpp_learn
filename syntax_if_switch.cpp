#include <iostream>


using namespace std;


//简单的if
bool isRunYear(int year){
    if ( (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)  )
    {
        return true;
    }
    return false;
}


//typedef 表示把 _COLOR 命名为color
typedef enum _COLOR {
    RED,
    GRAY,
    GREEN,
    UNKOWN
}color;


//多个分支的if
void printColor(color colors){
 if(colors == RED){
     cout << "红色" << endl;
 }else if(colors == GRAY){
     cout << "灰色" << endl;
 }else{
     cout << "未知" << endl;
 }
}


void printColor2(color colors){
    switch (colors)
    {
    case RED: 
     cout << "红色" << endl;
        break;
    
    default:
     cout << "默认" << endl;
        break;
        
    }
}

void printColor3(){
    int arrays[4] = {'a','b','c','d'};
    int length = sizeof(arrays) / sizeof(arrays[0]);
    for (size_t i = 0; i < length; i++)
    {
        cout << arrays[i] << endl;
    }

    for (auto &item : arrays){
        cout << item << endl;
    }

    while (length > 0)
    {
        length--;
        cout << arrays[length] << endl;
    }
     
}
//if语句
// if(条件) {
//     要执行的语句     
// }else {
//
// }
// 同Java
int main(){
    
    color color0;

    color0 = RED;

    printColor(color0);
    printColor2(color0);
    printColor3();
    return 0;
}