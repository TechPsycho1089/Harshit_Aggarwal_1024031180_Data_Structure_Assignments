#include <iostream>
using namespace std;
class stack{
    int *arr;
    int size;
    int top;
    public:
    stack(int size){                    //stack constructor
        arr[size];
        top=-1;
        this->size = size;
    }
    ~stack(){                           //stack destructor
        delete [] arr;
    }
    bool isEmpty(){                     // return true if stack is empty
        if (top==-1)return true;
        return false;
    }
    bool isFull(){                      //return true if stack is full.
        if (top==size-1) return true;
        return false;
    }
    void push(int x){                   // add a new element in the stack if it isn't full.
        if (isFull()){   //stack is full
            cout<<"Stack is full.";return;
        }
        arr[++top]=x;                   //push a new element into the stack
    }
    void pop(){                          //pop a element from the stack if it is not empty.
        if (isEmpty()) {
            cout<<"Stack is empty.";return;
        }
        cout<<"Popped element:"<<arr[top--]<<endl;
    }
    void display(){                      //display all the elements.
        if (isEmpty()){                   //check if stack is empty
            cout<<"Stack is empty.";return;
        }
        for (int i=top;i>=0;i--){    //display all element in the array.
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
    int peek(){
        if (isEmpty()){
            cout<<"Stack is empty.";return -1;     //Returns nothing if the stack is empty.
        }
        return arr[top];
    }
};

int main() {
    stack s(5);  // create stack of size 5

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << "Stack elements: ";
    s.display();

    cout << "Top element is: " << s.peek() << endl;
    
    s.pop();
    s.pop();

    cout << "Stack after popping: ";
    s.display();

    return 0;
}