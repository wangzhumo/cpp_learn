#include "advance/adapter.cpp"


int main() {
    // 实例化一个Adapter
    RectAdapterCon adapter1(1,2,3,4);
    RectBase* rect = &adapter1;
    rect->draw("TEST Adapter1");
    return 0;
}
