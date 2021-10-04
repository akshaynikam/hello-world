#include <iostream>

using namespace std;

class stacks {
    int n;
    int capacity;
    int next;
    int *top;
    int *data;
    int *index;

public:
    stacks(int n, int capacity) {
        this->n = n;
        this->capacity = capacity;
        next = 0;
        top = new int[n];

        for (int i = 0; i < n; i++) top[i] = -1;
        data = new int[capacity];
        index = new int [capacity];

        for (int i = 0; i < capacity - 1; i++)
            index[i] = i + 1;
        index[capacity - 1] = -1;
    }

    void push(int stack, int value) {
        if (stack < 0 || stack >= n) {
            cout << "push: invalid stack\n";
            return;
        }

        if (next == -1) {
            cout << "push: stack full\n";
            return;
        }

        int cur = next;
        next = index[cur];
        index[cur] = top[stack];
        top[stack] = cur;
        data[cur] = value;
    }

    int pop(int stack) {
        if (stack < 0 || stack >= n) {
            cout << "pop: invalid stack\n";
            return -1;
        }

        if (top[stack] == -1) {
            cout << "pop: stack empty\n";
            return -1;
        }

        int cur = top[stack];
        int value = data[cur];
        top[stack] = index[cur];
        index[cur] = next;
        next = cur;
        return value;
    }

    void status() {
        cout << "Number of Stacks : " << n << endl;
        cout << "Capacity of Stacks : " << capacity << endl;
        cout << "Top : ";
        for (int i = 0; i < n; i++)
            cout << top[i] << " ";
        cout << "\nIndex : ";
        for (int i = 0; i < capacity; i++)
            cout << index[i] << " ";

        cout << "\nNext Available : " << next << endl;
    }
};

int main() {
    stacks st(3, 10);

    st.push(0, 67);
    st.push(2, 47);
    st.push(1, 57);
    st.push(2, 46);
    st.push(1, 56);
    st.push(1, 55);
    st.push(0, 66);
    st.push(0, 65);
    st.push(2, 45);
    st.push(1, 54);
    st.push(0, 67);
    st.push(3, 67);

    cout << st.pop(0) << endl;
    cout << st.pop(0) << endl;
    cout << st.pop(0) << endl;

    cout << st.pop(1) << endl;
    cout << st.pop(1) << endl;
    cout << st.pop(1) << endl;
    cout << st.pop(1) << endl;

    cout << st.pop(2) << endl;
    cout << st.pop(2) << endl;
    cout << st.pop(2) << endl;
    cout << st.pop(2) << endl;
    cout << st.pop(-1) << endl;

    st.status();

    st.push(1, 11);
    st.push(1, 22);
    st.push(1, 33);
    st.push(1, 44);
    st.push(1, 55);
    st.push(1, 66);
    st.push(1, 77);
    st.push(1, 88);
    st.push(1, 99);
    st.push(1, 101);
    st.push(1, 101);

    cout << st.pop(1) << endl;
    cout << st.pop(1) << endl;
    cout << st.pop(1) << endl;
    cout << st.pop(1) << endl;
    cout << st.pop(1) << endl;
    cout << st.pop(1) << endl;
    cout << st.pop(1) << endl;
    cout << st.pop(1) << endl;
    cout << st.pop(1) << endl;
    cout << st.pop(1) << endl;
    cout << st.pop(1) << endl;

    st.status();


    return 0;
}
