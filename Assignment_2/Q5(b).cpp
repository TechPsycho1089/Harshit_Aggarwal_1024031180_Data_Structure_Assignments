#include <iostream>
using namespace std;
class tridiagnolMatrix{
    int n;
    int *A;
    public:
    tridiagnolMatrix(int n){
        this->n=n;
        A = new int[3*n-2];
        for (int i=0;i<3*n-2;i++) A[i]=0;
    }
    void set(int i,int j,int x){
        if (i==j) A[i]=x;
        if (i-j==1) A[n+i-1]=x;
        if (j-i==1) A[2*n+i-1]=x;
    }
    int get(int i, int j, int x){
        if (i==j) return A[i];
        if (i-j==1) return A[n+i-1];
        if (j-i==1) return A[2*n+i-1];
        return 0;
    }
    void display(){
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (i-j==1) cout<<A[n+i-1]<<" ";
                else if (i==j) cout<<A[i]<<" ";
                else if (j-i==1) cout<<A[2*n+i-1]<<" ";
                else cout<<"0 ";
            }
            cout<<endl;
        }
    }
};

int main(){
    tridiagnolMatrix mat(7);
    
    mat.set(0,0,1); mat.set(0,1,2);
    mat.set(1,0,3); mat.set(1,1,4); mat.set(1,2,5);
    mat.set(2,1,6); mat.set(2,2,7); mat.set(2,3,8);
    mat.set(3,2,9); mat.set(3,3,10); mat.set(3,4,11);
    mat.set(4,3,12); mat.set(4,4,13);

    cout << "Tridiagonal Matrix:" << endl;
    mat.display();

    return 0;
}