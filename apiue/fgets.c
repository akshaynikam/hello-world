#include <stdio.h>

int main() {
    char buf[80] = {0};

    while (fgets(buf, 80, stdin) != NULL) {
        fputs(buf, stdout);
    }

    return 0;
}
