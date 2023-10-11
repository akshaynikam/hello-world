#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void charatatime(char* str) {
    char* ptr;
    int c;

    for (ptr = str; (c = *ptr++);)
        putc(c, stdout);
}

int main() {
    setbuf(stdout, NULL);

    if (0 == fork())
        charatatime("output from child\n");
    else
        charatatime("output from parent\n");

    exit(0);
}
