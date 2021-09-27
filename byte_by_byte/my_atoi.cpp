#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

int myAtoI(char* str) {
    int sign = 1;
    int result = 0;

    int i = 0;
    while (str[i]) {
        if (str[i] == ' ' || str[i] == '+') {
            i++;
            continue;
        }

        if (str[i] == '-') {
            sign = -1;
            i++;
            continue;
        }

        if (str[i] >= '0' && str[i] <= '9') {
            int val = str[i] - '0';
            result = result * 10 + val;
        } else break;
        i++;
    }

    return result * sign;
}

int main(int argc, char** argv) {
    std::cout << myAtoI(argv[1]) << std::endl;

    return 0;
}
