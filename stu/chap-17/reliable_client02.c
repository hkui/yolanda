#include "../lib/common.h"

# define MESSAGE_SIZE 102400

void sigfun(int signo){
    printf("signo=%d\n",signo);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        error(1, 0, "usage: reliable_client02 <IPaddress>");
    }
    printf("pid=%d\n",getpid);

    int socket_fd = tcp_client(argv[1], SERV_PORT);

    signal(SIGPIPE, sigfun);
    signal(SIGUSR1, sigfun);

    char *msg = "network programming";
    ssize_t n_written;

    int count = 10000000;
    while (count > 0) {
        n_written = send(socket_fd, msg, strlen(msg), 0);
        fprintf(stdout, "send into buffer %ld \n", n_written);
        if (n_written <= 0) {
            error(1, errno, "send error");
            return -1;
        }
        count--;
    }
    return 0;
}
//gcc reliable_client02.c ../lib/tcp_client.c -o reliable_client02 -w

