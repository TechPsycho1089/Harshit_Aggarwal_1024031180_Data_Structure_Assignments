#include <iostream>
using namespace std;

class upperTriMatrix{
    int n;
    int *A;
    public:
    upperTriMatrix(int n){
        int m = n*(n+1)/2;
        this->n=n;
        A=new int[m];
        for (int i=0;i<m;i++) A[i]=0;
    }
    int index(int i,int j) {return j*(j+1)/2+i;}
    void set(int i,int j,int x){
        if (i<=j) A[index(i,j)]=x; 
    }
    int get(int i, int j){
        if (i<=j) return A[index(i,j)];
        return 0;
    }
    void display(){
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (i<=j) cout<<A[index(i,j)]<<" ";
                else cout<<"0 ";
            }
            cout<<endl;
        }
    }
};

int main() {
    int n = 4;
    upperTriMatrix mat(n);

    // Example values
    mat.set(0,0,1); mat.set(0,1,2); mat.set(0,2,3); mat.set(0,3,4);
    mat.set(1,1,5); mat.set(1,2,6); mat.set(1,3,7);
    mat.set(2,2,8); mat.set(2,3,9);
    mat.set(3,3,10);

    cout << "Upper Triangular Matrix:" << endl;
    mat.display();

    return 0;
}