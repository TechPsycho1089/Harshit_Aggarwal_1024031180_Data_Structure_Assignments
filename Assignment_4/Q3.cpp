#include<iostream>
#include<queue>
using namespace std;

void interleave(queue<int> &q){
    int n = q.size()/2;
    queue<int> firsthalf;
    for (int i=0;i<n;i++){
        firsthalf.push(q.front());
        q.pop();
    }
    for (int i=0;i<n;i++){
        q.push(firsthalf.front());
        firsthalf.pop();
        q.push(q.front());
        q.pop();
    }
    while (!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}

int main(){
    queue<int> q;
    int num;
    for (int i=0;i<6;i++){
        cin>>num;
        q.push(num);
    }
    interleave(q);
    return 0;
}