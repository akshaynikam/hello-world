#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    std::cout << "User ID: " << getuid() << std::endl;
    std::cout << "Effective user ID: " << geteuid() << std::endl;
    std::cout << "Group ID: " << getgid() << std::endl;
    std::cout << "Effective group ID: " << getegid() << std::endl;
    
    if (-1 == setgid(1000)) {
        std::cerr << "failed to set effective id\n";
        return -1;
    }

    if (-1 == setuid(1000)) {
        std::cerr << "failed to set effective id\n";
        return -1;
    }

    std::cout << "===========================\n";
    std::cout << "After setting user and group ID\n";
    std::cout << "User ID: " << getuid() << std::endl;
    std::cout << "Effective user ID: " << geteuid() << std::endl;
    std::cout << "Group ID: " << getgid() << std::endl;
    std::cout << "Effective group ID: " << getegid() << std::endl;

    auto fd = open("/tmp/aksh", O_WRONLY | O_CREAT, 0755);
    if ( -1 == fd) {
        std::cerr << "Failed to create file\n";
        return -1;
    }

    close(fd);  

    return 0;
}
