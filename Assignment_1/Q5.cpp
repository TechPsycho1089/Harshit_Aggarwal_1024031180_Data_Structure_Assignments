#include<iostream>
#include <vector>
using namespace std;
void display(int array[],int size){
    for (int i = 0;i<size;i++){
        cout<<array[i]<<" ";
    }   
    cout<<endl; 
}
void input(vector<vector<int>>& mat){
    for (int i=0;i<mat.size();i++){
        for (int j=0;j<mat[i].size();j++){
            cin>>mat[i][j];
        }
    }
}
void rowsum(vector<vector<int>> mat, int arr[]){
    int sum;
    for (int i=0;i<mat.size();i++){
        for (int j=0;j<mat[0].size();j++){
            sum=sum+mat[i][j];
        }
        arr[i]=sum;sum=0;
    }
}
void colsum(vector<vector<int>> mat, int arr[]){
    int sum;
    for (int i=0;i<mat.size();i++){
        for (int j=0;j<mat[0].size();j++){
            sum=sum+mat[j][i];
        }
        arr[i]=sum;sum=0;
    }
}

int main(){
    vector<vector<int>> mat;
    int row, col;
    cout<<"Enter the rows and columns: ";
    cin>>row>>col;
    mat.resize(row,vector<int>(col));
    input(mat);
    int rowSum[mat.size()];
    int colSum[mat[0].size()];

    rowsum(mat, rowSum);
    colsum(mat, colSum);

    display(rowSum,mat.size());
    display(colSum,mat[0].size());
    return 0;
}