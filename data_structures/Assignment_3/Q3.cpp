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
    T pop(){                          //pop a element from the stack if it is not empty.
        if (isEmpty()) return T();
        return arr[top--];
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
bool isClosingBracket(char ch){                          //returns true if inputed char is closing bracket
    if (ch=='}'||ch==']'||ch==')') return true;
    return false;
}
bool isOpeningBracket(char ch){                          //returns true if inputed char is opening bracket
    if (ch=='{'||ch=='['||ch=='(') return true;
    return false;
}
bool isBracketMatching(char ch1,char ch2){               //returns true if matching brackets are passed as parameter. Note: ch1 is opening and ch2 is closing.
    if ((ch1=='{'&&ch2=='}')||(ch1=='['&&ch2==']')||(ch1=='('&&ch2==')')) return true;
    return false;
}
// bool parenthesisChecker(string str){                    //returns true if the expression is balanced.
//     int len=length(str);
//     char char1;             //will store char poped from S1.
//     char char2;             //will store char poped from S2 which will contain all closing brackets.
//     stack<char> S2(100),S1(100);
//     for (int i=0;i<len;i++) S1.push(str[i]);    //pushes whole expression in S1.
//     for (int i=0;i<len;i++){                    //poped char one by one from S1 and stores them in char1.
//         char1=S1.pop(); 
//         if (isClosingBracket(char1)){                   //checks if poped char is closing bracket.
//             S2.push(char1);
//         }
//         else if(isOpeningBracket(char1)){               //checks if poped char is opening bracket.
//             char2=S2.pop();
//             if (S2.isEmpty()||!isBracketMatching(char1,char2))return false;             //checks for unbalanced expression.
//         }
//         else if (S1.isEmpty()||!S2.isEmpty())return false;                              //check if S1 is empty but S2 is not empty
//         return true;          
//     }
//     S1.display();
//     S2.display();
//     return true;
// }

bool parenthesisChecker(string str){                        //returns true if the expression is balanced.
    int len=length(str);
    stack<char> S1(100);
    for (int i=0;i<len;i++){
        if (isOpeningBracket(str[i]))S1.push(str[i]);        //pushes closing brackets in S1.
        else if(isClosingBracket(str[i])){                   
            if(!isBracketMatching(S1.pop(),str[i]))return false;             //checks opening bracket with opening bracket by poping from S1.
        }
    }
    if (S1.isEmpty())return true;                           //return true if S1 is empty after whole expression has been executed
    return false;
}

int main(){
    // stack<char> S(100);
    // string str;
    // cout<<"Enter the string: ";
    // cin>>str;
    // for (int i=0;i<length(str);i++){
    //     S.push(str[i]);
    // }
    // S.display();
    string str1;
    stack<char> S1(100);

    cout<<"Enter an expression that only contains only parenthesis. ";
    cin>>str1;
    if (parenthesisChecker(str1)) cout<<"Balanced expression."<<endl;
    else cout<<"Unbalanced expression."<<endl;
    return 0;
}
