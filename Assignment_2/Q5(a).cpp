#include <iostream>
#include <vector>
using namespace std;
class diagnolMatrix{
    int n;
    int *A;
    public:
    diagnolMatrix(int n){
        this->n=n;
        A = new int[n];
        for (int i=0;i<n;i++) A[i]=0;
    }
    void set(int i,int j,int x){
        if (i==j) A[i]=x;
    }
    int get(int i,int j){
        if (i==j) return A[i];
        return 0;
    }
    void display(){
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (i==j) cout<<A[i]<<" ";
                else cout<<"0 ";
            }
            cout<<endl;
        }
    }
};

int main(){
    diagnolMatrix ob1(4);
    ob1.set(2,2,5);
    ob1.set(3,3,3214);
    int a=ob1.get(3,3);
    cout<<a<<endl;
    ob1.display();
    return 0;
}