#include <iostream>
#include <memory>
#include <string>

using namespace std;



//unique_ptr
// 是专属所有权,unique_ptr管理的内存,只能被一个对象持有,不支持赋值和复制
//
// 如果一定要使用,因为unique_ptr禁止拷贝语义,我们可以使用 std::move()进行控制权转移
int main(){
    
    //定义范围
    {
        auto q1 = unique_ptr<int>(new int(12));
        
    }
    //当程序运行到这里,说明 q1 已经出了它的作用范围,此时就已经被释放了.


    // unique_ptr
    auto w = std::unique_ptr<int>(new int(10));
    cout << *(w.get()) << endl;

    //unique_ptr  只支持通过move()指令来进行赋值,转移控制权
    auto w2 = std::move(w);
    //此时w2获得内存的所有权,而之前的w == nullptr

    cout << ((w.get() != nullptr)? *(w.get()) : -1 ) << endl;
    cout << ((w2.get() != nullptr)? *(w2.get()) : -1 ) << endl;

    return 0;
}
