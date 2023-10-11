#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int global = 10;

int main() {
    printf("before fork\n");
    if (0 == vfork()) {
        printf("in child\n");
        global++;
        _exit(0);
    }
    else
        printf("in parent\n");

    printf("pid: %u, global: %d\n", getpid(), global);

    return 0;
}
