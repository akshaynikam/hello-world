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
    auto fd = open("./data/pwrite.txt", O_RDONLY);
    if ( -1 == fd) {
        std::cerr << "Failed to open file for reading\n";
        return -1;
    }

    std::cout << "First fd : " << fd << std::endl;

    auto fd1 = dup(fd);
    if ( -1 == fd1) {
        std::cerr << "Failed to open file for reading\n";
        return -1;
    }

    std::cout << "second fd : " << fd1 << std::endl;
    char* buff = new char[1024];

    _read(fd, buff, 6);

    std::cout << buff << std::endl;

    _read(fd1, buff, 6);

    std::cout << buff << std::endl;

    delete[] buff;

    close(fd);  

    return 0;
}
