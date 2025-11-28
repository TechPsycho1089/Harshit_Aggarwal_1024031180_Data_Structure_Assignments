#include<iostream>
#include<math.h>
using namespace std;

class sparseMatrix{
    int **arr;
    int maxZero;
    int count,m,n;
    public:
    //constructor.
    sparseMatrix(int rows, int columns, int maxZero){
        arr = new int*[maxZero];
        for (int i=0;i<maxZero;i++) arr[i] = new int [3];
        count = 0;
        m=rows;
        n=columns;
        this->maxZero = maxZero;
    }
    //destructor.
    ~sparseMatrix(){
        for (int i=0;i<maxZero;i++) delete [] arr[i];
        delete [] arr;
    }
    void insert(int idx){
        for (int i=count;i>idx;i++){
            for (int j=0;j<3;j++) arr[i][j]=arr[i-1][j];
        }
        count++;
    }
    void set(int i,int j,int x){
        int k=0;
        while (k<count){
            if (i<arr[k][0]||(i==arr[k][0]&&j<arr[k][1])){
                insert(k);
                arr[k][0]=i;arr[k][1]=j;arr[k][2]=x;
                return;   
            }
            if (i==arr[k][0]&&j==arr[k][1]){
                arr[k][2]=x;return;
            }
            k++;
        }
    arr[count][0] = i;
    arr[count][1] = j;
    arr[count][2] = x;
    count++;
    }
    //Optimised bubble sort for sparse matrix.
    void bubbleSort(){
        for (int i=0;i<count;i++){
            bool flag= false;
            for (int j=0;j<count-i-1;j++){
                if (arr[j][0]>=arr[j+1][0]) {swap(arr[j],arr[j+1]);flag=true;} 
            }
            if (!flag) break;
        }
    }
    //print the matrix.
    void display(){
        int k=0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (arr[k][0]==i&&arr[k][1]==j&&k<count) {cout<<arr[k][2]<<" ";k++;}
                else cout<<"0 ";
            }
            cout<<endl;
        }
    }
    friend sparseMatrix Transpose(const sparseMatrix& T);
    friend void sparseMul(sparseMatrix A, sparseMatrix B);
};
//Transpose.
sparseMatrix Transpose(const sparseMatrix& S){
    sparseMatrix T(S.n,S.m,S.maxZero);
    for(int i=0;i<S.count;i++){
        T.arr[i][0] = S.arr[i][1];
        T.arr[i][1] = S.arr[i][0];
        T.arr[i][2] = S.arr[i][2];
    }
    T.count = S.count;
    T.bubbleSort();
    return T;
}
//Multiplication of sparse matrix.
// void sparseMul(sparseMatrix A, sparseMatrix B){
//     int k=0;
//     int sum=0;
//     sparseMatrix C(A.m,B.n,100);
//     B = Transpose(B);
//     // for (int i=0;i<count;i++){
//         for (int j=0;j<A.count;){
//             int Arow=A[k][0];
//             int Brow=B[j][0];
//             while(A[k][0]==Arow&&Brow==B[j][0]){
//                 if (A[k][1]==B[j][1]) sum += A[k][2]*B[j][2];
//                 else if (A[k][1]>B[j][1]) k++;
//                 else if (A[k][1]<B[j][1]) j++;
//             }
//             if (j!=A.count) k=Arow;
//             if (sum != 0){C.set(Arow,Brow);sum=0;}
//         }
//     // }
// }
void sparseMul(sparseMatrix A, sparseMatrix B){
    if (A.n != B.m){
        cout << "Multiplication not possible!" << endl;
        return;
    }

    sparseMatrix C(A.m, B.n, 100);
    sparseMatrix BT = Transpose(B);  // Work with B^T

    // For each row in A
    for (int i = 0; i < A.m; i++){
        // For each column in B (row in BT)
        for (int j = 0; j < BT.m; j++){
            int sum = 0;

            // Multiply row i of A with row j of BT
            for (int a = 0; a < A.count; a++){
                if (A.arr[a][0] != i) continue;  // pick only row i

                for (int b = 0; b < BT.count; b++){
                    if (BT.arr[b][0] != j) continue; // pick only row j of BT

                    if (A.arr[a][1] == BT.arr[b][1]){ // matching column index
                        sum += A.arr[a][2] * BT.arr[b][2];
                    }
                }
            }

            if (sum != 0) C.set(i, j, sum);
        }
    }

    cout << "Result matrix:" << endl;
    C.display();
}



int main(){
    sparseMatrix A(2, 3, 10);
    sparseMatrix B(3, 2, 10);

    // A = [ 1 0 2 ]
    //     [ 0 3 0 ]
    A.set(0,0,1);
    A.set(0,2,2);
    A.set(1,1,3);

    // B = [ 0 3 ]
    //     [ 1 0 ]
    //     [ 4 5 ]
    B.set(0,1,3);
    B.set(1,0,1);
    B.set(2,0,4);
    B.set(2,1,5);

    cout << "Matrix A:" << endl;
    A.display();
    cout << "Matrix B:" << endl;
    B.display();

    sparseMul(A, B);

    return 0;
}
