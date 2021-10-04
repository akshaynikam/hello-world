#include <iostream>

using namespace std;

int make_change(int n) {
    if (n == 0) return 0;
    if (n >= 25) return 1 + make_change(n - 25);
    if (n >= 10) return 1 + make_change(n - 10);
    if (n >= 5) return 1 + make_change(n - 5);
    else return 1 + make_change(n - 1);
}

int alternate(int n) {
    int coins = 0;

    if (n >= 25) {
        coins += n / 25;
        n = n % 25;
    }

    if (n >= 10) {
        coins += n / 10;
        n = n % 10;
    }

    if (n >= 5) {
        coins += n / 5;
        n = n % 5;
    }

    coins += n;

    return coins;
}

int main() {
    cout << make_change(1) << endl;
    cout << make_change(6) << endl;
    cout << make_change(49) << endl;

    cout << alternate(1) << endl;
    cout << alternate(6) << endl;
    cout << alternate(49) << endl;
    return 0;
}
