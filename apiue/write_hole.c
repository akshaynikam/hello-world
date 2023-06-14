#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    char buf1[] = "abcdefghij";
    char buf2[] = "ABCDEFGHIJ";
    int fd;

    if ((fd = creat("./data/file.hole", 0644)) < 0) {
        fprintf(stderr, "failed to create file\n");
        return 1;
    }

    if (write(fd, buf1, 10) != 10) {
        fprintf(stderr, "failed to write\n");
        return 1;
    }

    if (lseek(fd, 16384, SEEK_SET) == -1) {
        fprintf(stderr, "failed to seek\n");
        return 1;
    }

    if (write(fd, buf2, 10) != 10) {
        fprintf(stderr, "failed to write\n");
        return 1;
    }

    return 0;
}
