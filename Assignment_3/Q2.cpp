#include <iostream>
using namespace std;
template <typename T>
class stack{
    T *arr;
    int size;
    int top;
    public:
    stack(int size){                    //stack constructor
        arr = new T [size];
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
    void push(T x){                   // add a new element in the stack if it isn't full.
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
int length(string str){                             //Returns the length the of the string.
    int count=0;        
    while (str[count]!='\0')count++;
    return count;
}

int main(){
    stack<char> S(100);
    string str;
    cout<<"Enter the string: ";
    cin>>str;
    for (int i=0;i<length(str);i++){
        S.push(str[i]);
    }
    S.display();
    return 0;
}
