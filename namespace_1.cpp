#include <iostream>

using namespace std;

namespace playground
{
    int printInt(int value){
        cout<< "playground-A : " << value << endl;
    }

}

namespace workspace{
    int printInt(int value){
        cout << "workspace-A : " << value << endl;
    }
}

//using namespace playground;

int main(){

    //一旦声明了 using namespace playground;
    //后面自己再写空间：：函数就不管用了，所以如果要同时使用就都使用  namespace::func的方式
    workspace::printInt(10086);
    playground::printInt(10086);
    return 0;
}
