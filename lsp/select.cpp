#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#define TIMEOUT 5
#define BUF_LEN 1024

int main() {
    struct timeval tv;
    fd_set readfds;
    int ret;

    tv.tv_sec = 5;
    tv.tv_usec = 0;

    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    ret = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &tv);

    if (ret == -1) {
        fprintf(stderr, "select failed\n");
        return 1;
    } else if (!ret) {
        printf("%d seconds elapsed\n", TIMEOUT);
        return 0;
    }

    if (FD_ISSET(STDIN_FILENO, &readfds)) {
        char buf[BUF_LEN + 1];
        int len;

        len = read(STDIN_FILENO, buf, BUF_LEN);
        if (len == -1) {
            fprintf(stderr, "read failed\n");
            return 1;
        }

        if (len) {
            buf[len] = '\0';
            printf("read: %s\n", buf);
        }

        return 0;
    }

    fprintf(stderr, "this should not happen!\n");
    return 1;
}
