#include<iostream>
using namespace std;
#define MAXLEN 10

class A {
    int front, rear;
    public:
    int arr[MAXLEN];

    A() { front = -1; rear = -1; }

    bool isempty() {
        if (front == -1 && rear == -1) return true;
        else if (front > rear) return true;
        else return false;
    }

    bool isfull() {
        if (rear == MAXLEN - 1) return true;
        else return false;
    }

    void enqueue(int ele) {
        if (isfull()) cout << "overflow\n";
        else if (front == -1 && rear == -1) {
            front = 0; rear = 0; arr[rear] = ele;
        } else {
            rear++; arr[rear] = ele;
        }
    }

    int dequeue() {
        if (isempty()) {
            cout << "underflow\n"; return -1;
        } else {
            int val = arr[front];
            if (front == rear) { front = -1; rear = -1; }
            else front++;
            return val;
        }
    }

    void display() {
        if (isempty()) { cout << "Queue is empty\n"; return; }
        for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << "\n";
    }

    int peek() {
        if (isempty()) { cout << "nothing to show\n"; return -1; }
        else return arr[front];
    }
};

int main() {
    A q;
    char choice;
    do {
        cout << "enter a number between 1 to 7\n";
        cout << "enter 1 to check for empty queue\n";
        cout << "enter 2 to check for if the queue is full\n";
        cout << "enter 3 to insert an element\n";
        cout << "enter 4 to remove starting element of your queue\n";
        cout << "enter 5 to display your entered elements\n";
        cout << "enter 6 to peek at youtrr first element of queue\n";
        cout << "enter 7 to exit\n";
        cin >> choice;
        switch (choice) {
            case '1': {
                if (q.isempty()) cout << "Queue is empty\n";
                else cout << "Queue is not empty\n";
                break;
            }
            case '2': {
                if (q.isfull()) cout << "Queue is full\n";
                else cout << "Queue is not full\n";
                break;
            }
            case '3': {
                int val; cout << "enter the element to be inserted in queue\n";
                cin >> val; q.enqueue(val); break;
            }
            case '4': {
                int removed = q.dequeue();
                if (removed != -1) cout << "Removed element: " << removed << "\n";
                break;
            }
            case '5': { q.display(); break; }
            case '6': {
                int x = q.peek();
                if (x != -1) cout << x << "\n";
                break;
            }
            case '7': { cout << "exiting...\n"; break; }
            default: cout << "Invalid input, try again\n";
        }
    } while (choice != '7');
    return 0;
}
