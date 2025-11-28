#include<iostream>
using namespace std;
#define MAX 10

class queue{
    int rear,front;
    int arr[MAX];
    public:
    queue(){
        rear=front=-1;
    }
    void enqueue(int x){
        if (rear==MAX-1){
            cout<<"Overflow.";
        }
        if (rear==-1&&front==-1){
            rear++;front++;
            arr[rear]=x;
        }
        else{
            rear++;
            arr[rear]=x;
        }
    }
    void dequeue(){
        if (rear==-1){
            cout<<"Underflow";
        }
        else{
            if (front==rear){
                front=rear=-1;
            }
            front++;
        }
    }
    bool isEmpty(){
        if (rear==-1){
            return true;
        }
        return false;
    }
    bool isFull(){
        if (front==0&&rear==MAX-1) return true;
        return false;
    }
    void display(){
        if (!isEmpty()){
            for (int i=front;i<=rear;i++) cout<<arr[i]<<" ";
            cout<<endl;
        }else{cout<<"Underflow.";}
    }
    void peek(){
        if (!isEmpty()){
            cout<<arr[front]<<endl;
        }
    }
};

int main() {
    queue q;
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