#include <iostream>
#include <stack>

using namespace std;

void insert_at_last(stack<int>& st, int ele) {
    if (st.empty()) st.push(ele);
    else {
        int temp = st.top();
        st.pop();
        insert_at_last(st, ele);
        st.push(temp);
    }
}

void reverse(stack<int>& st) {
    if (!st.empty()) {
        int temp = st.top();
        st.pop();
        reverse(st);
        insert_at_last(st, temp);
    }
}

void print(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;
}

int main() {
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    print(st);
    reverse(st);
    print(st);

    return 0;
}
