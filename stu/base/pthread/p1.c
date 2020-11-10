#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

void *pth_fun(void *pth_arg){
    while(1){
        printf("pid=%d, tid=%u\n",getpid(),pthread_self());
        sleep(1);
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    pthread_t tid=0;

    pthread_create(&tid,NULL,pth_fun,NULL);
    printf("tid=%u\n",tid); //typedef unsigned long int pthread_t;
    pthread_create(&tid,NULL,pth_fun,NULL);
    printf("tid=%u\n",tid); //typedef unsigned long int pthread_t;


    while(1){
        printf("pid=%d, tid=%u\n",getpid(),pthread_self());
        sleep(3);
        printf("-----------------\n");
    }

    return 0;
}