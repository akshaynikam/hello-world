#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void _read(int fd, char* buff, int len) {
    ssize_t ret = 0;

    while (len != 0 && (ret = read(fd, buff, len))) {
        if (ret == -1) {
            if (errno == EINTR) {
                continue;
            }

            std::cerr << "read error\n";
            break;
        }

        len -= ret;
        buff += ret;
    }
}

int main() {
    auto fd = open("./read.cpp", O_RDONLY);
    if ( -1 == fd) {
        std::cerr << "Failed to open file for reading\n";
        return -1;
    }

    char* buff = new char[1024];

    _read(fd, buff, 1024);

    std::cout << buff << std::endl;

    delete[] buff;

    close(fd);  

    return 0;
}
