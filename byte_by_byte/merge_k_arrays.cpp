#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class node {
public:
    int array;
    int index;
    int value;
    node(int array, int index, int value) {
        this->array = array;
        this->index = index;
        this->value = value;
    }
};

class compare {
    public:
        bool operator() (node* n1, node* n2) {
            return n1->value > n2->value;
        }
};

void merge(int arr[3][3], int n, int m) {
    priority_queue<node*, vector<node*>, compare> pq;

    for (int i = 0; i < n; i++) {
        pq.push(new node(i, 0, arr[i][0]));
    }

    int* result = new int[n * m];
    int k = 0;
    while (!pq.empty()) {
        result[k++] = pq.top()->value;
        if (pq.top()->index < n - 1)
            pq.push(new node(pq.top()->array, pq.top()->index + 1, arr[pq.top()->array][pq.top()->index + 1]));
        pq.pop();
    }

    for (int i = 0; i < k; i++)
        cout << result[i] << " ";
    cout << endl;
}

int main() {
    int arr[3][3] = {{1, 4, 7},
                     {2, 5, 8},
                     {3, 6, 9}};

    merge(arr, 3, 3);

    return 0;
}
