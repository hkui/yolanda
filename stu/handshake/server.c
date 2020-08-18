//
// Created by hkui2015 on 2020/8/17.
//
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <arpa/inet.h>

int main(){
    int listenfd=socket(PF_INET,SOCK_STREAM,0);
    int on = 1;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

    struct sockaddr_in sock_in ;
    bzero(&sock_in, sizeof(sock_in));

    socklen_t address_len;
    sock_in.sin_family=AF_INET;
    sock_in.sin_port=htons(8090);
    sock_in.sin_addr.s_addr=htonl(INADDR_ANY);
    address_len= sizeof(sock_in);

    int bindres= bind(listenfd, (const struct sockaddr *)&sock_in,address_len);
    if(bindres<0){
        perror ("bind");
        exit (EXIT_FAILURE);
    }
    int clilen,connfd;
    listen (listenfd, 1024);


    socklen_t addrlen;
    int n;
    char buf[1024];
    struct sockaddr_in cliaddr = {0};

    for (;;) {
        clilen = sizeof(cliaddr);

        while(connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &clilen)){

            printf("port=%d\n",ntohs(cliaddr.sin_port));
            printf("ip=%s\n",inet_ntoa(cliaddr.sin_addr));

            n = read(connfd,&buf,1024);
            printf("n=%d\n",n);
        }

        //close(connfd);          /* 关闭连接套接字，注意不是监听套接字*/
    }

    return 0;
}

