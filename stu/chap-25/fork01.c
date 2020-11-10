#include "../lib/common.h"

#define MAX_LINE 4096


void child_run(int fd,int i) {
    char outbuf[MAX_LINE + 1];
    size_t outbuf_used = 0;
    ssize_t result;

    while (1) {
        char ch;
        result = recv(fd, &ch, 1, 0);
        if (result == 0) {
//            exit( i);
            printf("child pid===%d\n",getpid());
            exit(260);
            break;
        } else if (result == -1) {
            perror("read");
            break;
        }

        /* We do this test to keep the user from overflowing the buffer. */
        if (outbuf_used < sizeof(outbuf)) {
            outbuf[outbuf_used++] = ch;
        }

        if (ch == '\n') {
            send(fd, outbuf, outbuf_used, 0);
            outbuf_used = 0;
            continue;
        }
    }
}


void sigchld_handler(int sig) {
    printf("sig=%d\n",sig);
    pid_t wpid=0;
    int  status;

    while ((wpid=waitpid(-1, &status, WNOHANG)) > 0){
        printf("wpid =%d exited,rawstatus=%d \n",wpid,status);
        if(WIFEXITED(status)){
            printf("normal exit status=%d\n",WEXITSTATUS(status));
        }else{
            printf("unnormal exit!\n");
        }
    }
    return;
}

int main(int c, char **v) {
    int listener_fd = tcp_server_listen(SERV_PORT);
    printf("master pid=%d\n",getpid());
    signal(SIGCHLD, sigchld_handler);
    int i=0;
    while (1) {
        struct sockaddr_storage ss;
        socklen_t slen = sizeof(ss);
        int fd = accept(listener_fd, (struct sockaddr *) &ss, &slen);
        i++;
        if (fd < 0) {
            error(1, errno, "accept failed");
            exit(1);
        }

        if (fork() == 0) {
            close(listener_fd);
            printf("child pid=%d\n",getpid());
            child_run(fd,i);
            exit(0);
        } else {
            close(fd);
        }
    }

    return 0;
}
//gcc fork01.c ../lib/tcp_server25.c -o fork01 -w