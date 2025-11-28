#include <iostream>
using namespace std;

class symmetricTriMatrix{
    int n;
    int *A;
    public:
    symmetricTriMatrix(int n){
        int m = n*(n+1)/2;
        this->n=n;
        A=new int[m];
        for (int i=0;i<m;i++) A[i]=0;
    }
    int index(int i, int j){
        return i*(i+1)/2+j;
    }
    void set(int i,int j,int x){
        if (j<=i) A[index(i,j)]=x;
        else A[index(j,i)]=x;
    }
    int get(int i, int j){
        if (j<=i) return A[index(i,j)];
        else A[index(j,i)];
    }
    void display(){
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (j<=i) cout<<A[index(i,j)]<<" ";
                else cout<<A[index(j,i)]<<" ";
            }
            cout<<endl;
        }
    }
};

int main() {
    int n = 5;
    symmetricTriMatrix mat(n);

    // Fill with some demo values
    mat.set(0,0,11);
    mat.set(0,1,12);
    mat.set(0,2,13);
    mat.set(0,3,14);
    mat.set(0,4,15);

    mat.set(1,1,22);
    mat.set(1,2,23);
    mat.set(1,3,24);
    mat.set(1,4,25);

    mat.set(2,2,33);
    mat.set(2,3,34);
    mat.set(2,4,35);

    mat.set(3,3,44);
    mat.set(3,4,45);

    mat.set(4,4,55);

    cout << "Symmetric Matrix:" << endl;
    mat.display();

    return 0;
}