//
// Created by wangzhumo on 2020/7/30.
//

#include "../../includes/basic/const_test.h"

void testConst(){
    struct Person p = {"name",20};
    printf("Person name = %s  ,age = %d", p.name, p.age);
    testChangePerson(&p);
}

// 修饰参数，表示这个参数不可以修改
void testChangePerson(const struct Person *person){
    //person->age = 12;
    //不可以修改
    printf("Person name = %s  ,age = %d", person->name, person->age);
}