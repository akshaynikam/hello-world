#include <iostream>
#include <chrono>
#include <ctime>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    auto fd = open("./data/pwrite.txt", O_RDONLY);
    if ( -1 == fd) {
        std::cerr << "Failed to open file for reading\n";
        return -1;
    }

    char buff[1024] = {0};

    pread(fd, buff, 6, 7);

    std::cout << buff << std::endl;

    close(fd);

    return 0;
}
