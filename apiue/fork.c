#include <stdio.h>
#include <unistd.h>

int global = 10;

int main() {
    char buf[] = "Writing onto console\n";

    write(STDOUT_FILENO, buf, sizeof(buf));

    printf("before fork\n");
    if (0 == fork()) {
        printf("in child\n");
        global++;
    }
    else {
        sleep(1);
        printf("in parent\n");
    }

    printf("pid: %u, global: %d\n", getpid(), global);

    return 0;
}
