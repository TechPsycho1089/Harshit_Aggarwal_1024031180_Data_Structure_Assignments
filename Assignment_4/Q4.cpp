#include <iostream>
#include <string>
#include <queue>
using namespace std;

void firstNonRepeating(string s){
    queue<char> q;
    int freq[256]={0};
    for (char ch : s){
        if (ch == ' ') continue;
        freq[(unsigned char) ch]++;
        q.push(ch);
        while (!q.empty()&&freq[(unsigned char) q.front()]>1) q.pop();
        if(q.empty()){
            cout<<"-1 ";
        }else{
            cout<<q.front()<<" ";
        }
    }
    cout<<endl;
}


int main(){
    string str;
    cout<<"Enter the string.";
    getline(cin,str);
    firstNonRepeating(str);
    return 0;
}