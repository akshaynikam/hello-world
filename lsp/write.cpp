#include <iostream>
#include <chrono>
#include <ctime>
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

void _write(int fd, char* buff, int len) {
    ssize_t ret = 0;

    while (len != 0 && (ret = write(fd, buff, len))) {
        if (ret == -1) {
            if (errno == EINTR)
                continue;
            std::cerr << "write error\n";
            break;
        }

        len -= ret;
        buff += ret;
    }
}

int main() {
    auto rfd = open("./read.cpp", O_RDONLY);
    if ( -1 == rfd) {
        std::cerr << "Failed to open file for reading\n";
        return -1;
    }

    char* buff = new char[1024];

    _read(rfd, buff, 1024);

    auto wfd = open("./data/sample.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if ( -1 == wfd) {
        std::cerr << "Failed to open file for writing\n";
        return -1;
    }

    std::cout << std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()) << std::endl;

    _write(wfd, buff, strlen(buff));
    fsync(wfd);

    std::cout << std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()) << std::endl;

    delete[] buff;

    close(rfd);
    close(wfd);

    return 0;
}
