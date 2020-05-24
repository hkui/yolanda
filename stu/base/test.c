//
// Created by Administrator on 2020/5/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    printf("u_int32_t=%d\n", sizeof(u_int32_t));
    printf("size_t=%d\n", sizeof(size_t));

    char *s="abcde12345";
    printf("len=%d,sizeof=%d,s=%s\n",strlen(s), sizeof(s),s);

    return 0;
}
