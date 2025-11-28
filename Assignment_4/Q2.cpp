#include <iostream>
#define MAX 5
using namespace std;


class CircularQueue{
    int rear,front;
    int arr[MAX];
    public:
    CircularQueue(){
        front=rear=-1;
    }
    bool isEmpty(){
        if (front==-1)return true;
        return false;
    }
    bool isFull(){
        if (front==(rear+1)%MAX)return true;
        return false;
    }
    void enqueue(int x){
        if (front==-1&&rear==-1){
            rear++;front++;
            arr[front]=x;
        }
        else if (isFull()){
            cout<<"Overflow."<<endl;
        }
        else {
            rear=(rear+1)%MAX;
            arr[rear]=x;
        }
    }
    void dequeue(){
        if (isEmpty())cout<<"Underflow"<<endl;
        else {
            if (front==rear) rear=front=-1;
            else front=(front+1)%MAX;
        }
    }
    void display(){
        if (isEmpty()){cout<<"Queue is Empty.";return;}
        int i = front;
        while (true){
            cout<<arr[i]<<" ";
            if (i==rear)break;
            i = (i+1)%MAX;
        }
        cout<<endl;
    }
    void peek(){
        if (isEmpty())cout<<"Queue is Empty"<<endl;
        else {
            cout<<arr[front]<<endl;
        }
    }
};

int main() {
    CircularQueue q;
    char choice;
    do {
        cout << "enter a number between 1 to 7\n";
        cout << "enter 1 to check for empty queue\n";
        cout << "enter 2 to check for if the queue is full\n";
        cout << "enter 3 to insert an element\n";
        cout << "enter 4 to remove starting element of your queue\n";
        cout << "enter 5 to display your entered elements\n";
        cout << "enter 6 to peek at your first element of queue\n";
        cout << "enter 7 to exit\n";
        cin >> choice;
        switch (choice) {
            case '1': {
                if (q.isEmpty()) cout << "Queue is empty\n";
                else cout << "Queue is not empty\n";
                break;
            }
            case '2': {
                if (q.isFull()) cout << "Queue is full\n";
                else cout << "Queue is not full\n";
                break;
            }
            case '3': {
                int val; cout << "enter the element to be inserted in queue\n";
                cin >> val; q.enqueue(val); break;
            }
            case '4': {
                q.dequeue();
                break;
            }
            case '5': { q.display(); break; }
            case '6': {
                q.peek();
                break;
            }
            case '7': { cout << "exiting...\n"; break; }
            default: cout << "Invalid input, try again\n";
        }
    } while (choice != '7');
    return 0;
}