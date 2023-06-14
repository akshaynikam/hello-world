#include <stdio.h>
#include <unistd.h>
#include <poll.h>

int main() {
    struct pollfd fds[2];
    int ret;

    fds[0].fd = STDIN_FILENO;
    fds[0].events = POLLIN;

    fds[1].fd = STDOUT_FILENO;
    fds[1].events = POLLOUT;

    ret = poll(fds, 2, 5 * 1000);
    if (ret == -1) {
        fprintf(stderr, "poll filed\n");
        return 1;
    } else if (!ret) {
        printf("%d second elapsed\n", 5);
        return 0;
    }

    if (fds[0].revents & POLLIN) {
        printf("stdin is readable\n");
    }

    if (fds[1].revents & POLLOUT) {
        printf("stdout is writable\n");
    }

    return 0;
}
