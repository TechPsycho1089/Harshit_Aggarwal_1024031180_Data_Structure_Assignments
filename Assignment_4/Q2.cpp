#include <iostream>
#define MAX 5
using namespace std;

class CircularQueue {
    int arr[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = rear = -1;
    }

    bool isFull() {
        return (front == (rear + 1) % MAX);
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        if (isEmpty()) front = 0;
        rear = (rear + 1) % MAX;
        arr[rear] = x;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        int i = front;
        cout << "Queue: ";
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, val;

    do {
        cout << "\n1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\n";
        cin >> choice;
        switch (choice) {
            case 1: cin >> val; q.enqueue(val); break;
            case 2: q.dequeue(); break;
            case 3: cout << "Peek: " << q.peek() << endl; break;
            case 4: q.display(); break;
            case 5: cout << "Exiting\n"; break;
            default: cout << "Invalid\n";
        }
    } while (choice != 5);
    return 0;
}
