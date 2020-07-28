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

#endif //LEARN_CPP_THREAD_DEMO_H
