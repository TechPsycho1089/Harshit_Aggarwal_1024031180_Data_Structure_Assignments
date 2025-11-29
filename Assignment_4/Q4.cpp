#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void firstNonRepeating(string s) {
    queue<char> q;
    unordered_map<char, int> freq;

    for (char ch : s) {
        freq[ch]++;
        q.push(ch);

        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        if (q.empty()) cout << -1 << " ";
        else cout << q.front() << " ";
    }
    cout << endl;
}

int main() {
    string input;
    cout << "Enter string: ";
    cin >> input;
    firstNonRepeating(input);
    return 0;
}
