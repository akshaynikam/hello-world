#include <iostream>
#include <queue>

using namespace std;

class qstack {
    queue<int> primary;
    queue<int> secondary;

public:
    void push(int data) {
        secondary.push(data);

        while (!primary.empty()) {
            secondary.push(primary.front());
            primary.pop();
        }

        queue<int> temp = primary;
        primary = secondary;
        secondary = temp;
    }

    int pop() {
        if (primary.empty()) return -1;
        int data = primary.front();
        primary.pop();

        return data;
    }
};

int main() {
    qstack qs;

    qs.push(11);
    qs.push(22);
    qs.push(33);
    qs.push(44);
    qs.push(55);

    cout << qs.pop() << endl;
    cout << qs.pop() << endl;
    cout << qs.pop() << endl;
    cout << qs.pop() << endl;
    cout << qs.pop() << endl;
    cout << qs.pop() << endl;

    return 0;
}
