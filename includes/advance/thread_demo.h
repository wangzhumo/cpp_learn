//
// Created by wangzhumo on 2020/7/28.
//
// 一个线程的小demo
#ifndef LEARN_CPP_THREAD_DEMO_H
#define LEARN_CPP_THREAD_DEMO_H

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

// 排它锁
mutex g_mutex;

void test002(const char *msg) {
    g_mutex.lock();
    cout << "Test2" << msg << endl;
    g_mutex.unlock();
}

void test001() {
    g_mutex.lock();
    cout << "Test1 Hello" << endl;
    g_mutex.unlock();
}

void threadTest() {
    thread t1(test001);
    thread t2(test002, "Hello World");
    // join 确保子线程创建后，主线程等待子线程执行完毕再次执行
    t1.join();
    t2.join();
}

// 存钱
void deposit(mutex& m, int& money) {
//    m.lock();
//    for (int i = 0; i < 100; i++) {
//        money += 1;
//    }
//    m.unlock();
    // 锁的粒度要尽可能的小，
    // 这里，我们唯一共享的元素只有 money,只需要保护它即可
    for (int i = 0; i < 100; i++) {
        m.lock();
        money += 1;
        m.unlock();
    }
}

void withdraw(mutex& m,int& money){
    for (int i = 0; i < 100; i++) {
        m.lock();
        money -= 1;
        m.unlock();
    }
}

void threadMoney() {
    mutex v_mutex;
    int money = 1000;
    thread test1(deposit,ref(v_mutex),ref(money));
    thread test2(withdraw,ref(v_mutex),ref(money));

    test1.join();
    test2.join();
}


#endif //LEARN_CPP_THREAD_DEMO_H
