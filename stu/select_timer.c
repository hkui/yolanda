//
// Created by hkui2015 on 2019/11/24.
//
/**
 * 定时器
 */
#include <sys/select.h>

/* According to earlier standards */
#include <sys/time.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>


void print_err(char *str,int line,int err_no){
    printf("%d,%s:%s\n",line,str,strerror(err_no) );
    exit(-1);
}
void printTime(){
    time_t rawtime;
    struct tm *lt;
    time(&rawtime);//获取Unix时间戳。
    lt = localtime(&rawtime);//转为时间结构。
    printf ( "%d/%d/%d %d:%d:%d\n",lt->tm_year+1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);//输出结果
}


int main(){
    struct timeval timeout;
    int fd=0;
    fd_set readfds;
    FD_ZERO(&readfds); //把集合全部清空
    FD_SET(fd, &readfds);//将fd放到readfds集合中

    int ret;
    char buf[200];

    while(1){
        // 如果集合没动静就阻塞
        label:
        timeout.tv_sec=5;
        timeout.tv_usec=0;
        ret=select(fd+1,&readfds,NULL,NULL,&timeout);
        if(ret == -1 && errno == EINTR) goto label;
        else if(ret ==-1) print_err("select fail",__LINE__,errno);
        else if(ret >0){
            if(FD_ISSET(fd, &readfds)){
                bzero(buf,sizeof(buf));
                ret =read(fd,buf,sizeof(buf));
                if(ret>0) printf("buf=%s\n",buf );
            }
        }else if(ret ==0){
            printTime();
        }
    }
    return 0;
}





