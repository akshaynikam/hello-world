#include <stdio.h>
#include <unistd.h>

int main() {
    if (access("/etc/passwd", W_OK) == 0) {
        printf("access to read /etc/passwd\n");
    } else {
        printf("no access to read /etc/passwd\n");
    }

    return 0;
}
