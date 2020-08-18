//
// Created by hkui2015 on 2020/8/18.
//
#include <stdio.h>
#include <string.h>


int main(){
    char s1[10];
    char *s2;
    char s3[]="c is best";

    strcpy(s1,"php"); //不可以直接s1="php"
    s2="hello";

    printf("s1=%s\n",s1);
    printf("s2=%s\n",s2);
    printf("s3=%s\n",s3);
    s3[0]='a';
    printf("s3=%s\n",s3);
    return 0;

}
