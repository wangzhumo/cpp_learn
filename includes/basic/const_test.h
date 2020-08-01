//
// Created by wangzhumo on 2020/7/30.
//

#ifndef LEARN_CPP_CONST_TEST_H
#define LEARN_CPP_CONST_TEST_H

#ifdef __cplusplus
extern "C"{
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person{
    char name[100];
    int age;
};

void testConst();

void testChangePerson(const struct Person *person);

void testConstWithVar();

#ifdef __cplusplus
}
#endif // __cplusplus end


#endif //LEARN_CPP_CONST_TEST_H
