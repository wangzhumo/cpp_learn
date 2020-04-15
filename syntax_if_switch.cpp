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

    return 0;
}