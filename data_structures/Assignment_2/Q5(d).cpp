#include <iostream>
using namespace std;

class lowerTriMatrix{
    int n;
    int *A;
    public:
    lowerTriMatrix(int n){
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
    }
    int get(int i, int j){
        if (j<=i) return A[index(i,j)];
        return 0;
    }
    void display(){
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (j<=i) cout<<A[index(i,j)]<<" ";
                else cout<<"0 ";
            }
            cout<<endl;
        }
    }
};

int main() {
    int n = 4;
    lowerTriMatrix mat(n);

    // Example values
    mat.set(0,0,1);
    mat.set(1,0,2); mat.set(1,1,3);
    mat.set(2,0,4); mat.set(2,1,5); mat.set(2,2,6);
    mat.set(3,0,7); mat.set(3,1,8); mat.set(3,2,9); mat.set(3,3,10);

    cout << "Lower Triangular Matrix:" << endl;
    mat.display();

    return 0;
}