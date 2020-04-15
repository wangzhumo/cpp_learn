#include <iostream>
#include <memory>
#include <string>

using namespace std;



//unique_ptr
// 是专属所有权,unique_ptr管理的内存,只能被一个对象持有,不支持赋值和复制
//
// 如果一定要使用,因为unique_ptr禁止拷贝语义,我们可以使用 std::move()进行控制权转移
int main(){

    // unique_ptr
    auto w = std::make_unique<int>(10);


    return 0;
}
