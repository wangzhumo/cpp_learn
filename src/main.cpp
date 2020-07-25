#include "advance/observer_impl.cpp"


int main() {
    News news1;
    news1.getSomeNews("Message 1");

    User1 user1;
    User2 user2;

    // 添加到被观察者
    news1.addListener(&user1);
    news1.addListener(&user2);

    news1.getSomeNews("Message New.");

    return 0;
}
