#include <iostream>
#include<string>
using namespace std;
class stack{
    char *arr;
    int size, top;
    public:
    stack(){
        arr = new char [100];
        size =100;
        top=-1;
    }
    ~stack(){
        delete [] arr;
    }
    char peek(){
        return arr[top];                //returns element at the top of the stack
    }
    bool isEmpty(){                     // return true if stack is empty
        if (top==-1)return true;
        return false;
    }
    bool isFull(){                      //return true if stack is full.
        if (top==size-1) return true;
        return false;
    }
    char pop(){                          //pop a element from the stack if it is not empty.
        return arr[top--];
    }
    void push(char x){                   // add a new element in the stack if it isn't full.
        if (isFull()){   //stack is full
            cout<<"Stack is full.";return;
        }
        arr[++top]=x;                   //push a new element into the stack
    }
};
int precendence(char ch){
        if (ch=='^') return 3;
        if (ch=='*'||ch=='/') return 2;
        if (ch=='-'||ch=='+') return 1;
        return 0;
    }
void infixToPostfix(string s){
    stack st;
    string result;
    for (int i=0;i<s.length();i++){
        if ((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9')) result += s[i];
        else if (s[i]=='(') st.push(s[i]);
        else if (s[i]==')'){
            while (!st.isEmpty()&&st.peek()!='(') result += st.pop();
            st.pop();
        }
        else{
            while (!st.isEmpty()&&precendence(st.peek())>=precendence(s[i])) result += st.pop();
            st.push(s[i]);
        }
    }
    while (!st.isEmpty()) {
        result += st.pop();
    };
    cout<<result<<endl;
}

int main(){
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
	infixToPostfix(exp);
    return 0;
}