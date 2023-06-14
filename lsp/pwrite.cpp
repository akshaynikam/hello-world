#include <iostream>
#include <chrono>
#include <ctime>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    auto fd = open("./data/pwrite.txt", O_WRONLY);
    if ( -1 == fd) {
        std::cerr << "Failed to open file for writing\n";
        return -1;
    }

    char buff[1024] = {'P', 'a', 't', 'i', 'l'};


    std::cout << pwrite(fd, buff, 5, 7) << std::endl;

    close(fd);

    return 0;
}
