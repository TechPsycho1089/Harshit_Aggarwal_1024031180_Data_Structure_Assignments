#include <iostream>
#include <queue>
using namespace std;

class Stack{
    queue<int> q1;
    public:
    void push(int x){
        queue<int> q2;
        if (q1.empty()) q1.push(x);
        else {
            q2.push(x);
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
            q1=q2;
        }
    }
    void pop(){
        if (q1.empty()) {cout<<"stack is already empty.";return;}
        q1.pop();
    }
    int top(){
        return q1.front();
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << "Top element: " << s.top() << endl;
    s.pop();
    cout << "Top element after pop: " << s.top() << endl;
    s.pop();
    cout << "Top element after pop: " << s.top() << endl;
    s.pop();
    s.pop();
    return 0;
}
