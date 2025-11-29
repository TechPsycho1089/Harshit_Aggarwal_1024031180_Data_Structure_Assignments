#include <iostream>
#include <queue>
using namespace std;

void interleave(queue<int>& q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue has odd number of elements\n";
        return;
    }

    queue<int> firstHalf;
    for (int i = 0; i < n / 2; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();
        q.push(q.front());
        q.pop();
    }

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    int x;
    cout << "Enter 6 integers:\n";
    for (int i = 0; i < 6; i++) {
        cin >> x;
        q.push(x);
    }

    interleave(q);
    return 0;
}
