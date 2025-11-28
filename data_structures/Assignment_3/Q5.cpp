#include<iostream>
#include<math.h>
using namespace std;
template <typename T>

class stack{
    T *arr;
    int size,top;
    public:
    //constructor
    stack(int size){
        arr = new T [size];
        this->size = size;
        top =-1;
    }
    //destructor
    ~stack(){
        delete [] arr;
    }
    //return true if stack is full.
    bool isFull(){
        if (top==size-1) return true;
        return false;
    }
    //add a new element in the stack if it isn't full.
    void push(T x){
        if (isFull()){   
            cout<<"Stack is full.";return;
        }
        arr[++top]=x;
    }
    //pop a element from the stack if it is not empty.
    T pop(){
        return arr[top--];
    }
    //Takes a postfix expression as input, Evaluate and return the result.
};
int evaluatePostfix(string s){
    stack<int> st(100);
    for (int i=0;i<s.length();i++){
        if (s[i]>='0'&&s[i]<='9') st.push(s[i]-'0');
        else {
            int b=st.pop();
            int a=st.pop();
            switch(s[i]){
                case '^': st.push(pow(a,b));break;
                case '*': st.push(a*b);break;
                case '/': st.push(a/b);break;
                case '+': st.push(a+b);break;
                case '-': st.push(a-b);break;
            }
        }
    }
    return st.pop();
}

int main(){
    int sum = evaluatePostfix("231*+9-");
    cout<<"sum is: "<<sum<<endl;
    return 0;
}