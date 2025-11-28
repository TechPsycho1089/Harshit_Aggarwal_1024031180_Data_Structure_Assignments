#include <iostream>
#include <vector>
using namespace std;
void display(vector<vector<int>> mat){
    for (int i = 0;i<mat.size();i++){
        for (int j=0;j<mat[i].size();j++)
        cout<<mat[i][j]<<" ";
        cout<<endl;
    }    
}
void input(vector<vector<int>>& mat){
    for (int i=0;i<mat.size();i++){
        for (int j=0;j<mat[i].size();j++){
            cin>>mat[i][j];
        }
    }
}
void matrixTranspose(vector<vector<int>>& mat, vector<vector<int>>& T){
    T.resize(mat[0].size(),vector<int>(mat.size()));
    for (int i=0;i<mat.size();i++){
        for (int j=0;j<mat[i].size();j++){
            T[j][i]=mat[i][j];
        }
    }
}
void matrixMultiplication(vector<vector<int>> matA,vector<vector<int>> matB,vector<vector<int>>& matC){
    if (matA[0].size()!=matB.size()){
        cout<<"Multiplication not possible."<<endl;return;
    }
    matC.resize(matA.size(),vector<int>(matB[0].size()));
    int sum=0;
    for (int i=0;i<matA.size();i++){
        for (int j=0;j<matB.size();j++){
            for (int k=0;k<matA[0].size();k++) sum = sum+matA[i][k]*matB[k][j];
            matC[i][j]=sum;
            sum=0;
        } 
    }
}


int main(){
    // int rows, cols;
    // cout << "Enter rows and cols: ";
    // cin >> rows >> cols;
    // vector<vector<int>> matrix;
    // vector<vector<int>> T;
    // matrix.resize(rows,vector<int>(cols));
    // input(matrix);
    // matrixTranspose(matrix,T);
    // display(T);
    //matrix multiplication
    int rowsA, colsA, rowsB, colsB;


    cout << "Enter rows and cols of Matrix A: ";
    cin >> rowsA >> colsA;
    vector<vector<int>> A(rowsA, vector<int>(colsA));
    cout << "Enter elements of Matrix A:" << endl;
    input(A);

    cout << "Enter rows and cols of Matrix B: ";
    cin >> rowsB >> colsB;
    vector<vector<int>> B(rowsB, vector<int>(colsB));
    cout << "Enter elements of Matrix B:" << endl;
    input(B);

    cout << "\nMatrix A:" << endl;
    display(A);
    cout << "\nMatrix B:" << endl;
    display(B);

    vector<vector<int>> C;
    matrixMultiplication(A, B, C);

    if (!C.empty()) {
        cout << "\nMatrix A * Matrix B:" << endl;
        display(C);
    }

    return 0;
}
    
