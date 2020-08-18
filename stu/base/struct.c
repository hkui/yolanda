//
// Created by hkui2015 on 2020/8/18.
//
#include <stdio.h>
#include <string.h>

struct Person{
    char *name;
    char hobby[10];
    int age;
};
int main(){
    struct  Person p1;
    p1.age=20;
    p1.name="hkui";
    strcpy(p1.hobby,"足球");
    printf("name=%s,age=%d,hobby=%s\n",p1.name,p1.age,p1.hobby);
    struct Person *p2;
    p2=&p1;
    p2->name="Tom";
    printf("name=%s,age=%d,hobby=%s\n",p2->name,p2->age,p2->hobby);
    return 0;
}




