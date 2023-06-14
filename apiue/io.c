#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int n;
    char buf[4096] = {0};

    while ((n = read(STDIN_FILENO, buf, 4096)) > 0) {
        if (write(STDOUT_FILENO, buf, n) != n) {
            fprintf(stderr, "failed to write\n");
            return 1;
        }
    }

    if (n < 0) {
        fprintf(stderr, "read failed\n");
        return 1;
    }

    return 0;
}
