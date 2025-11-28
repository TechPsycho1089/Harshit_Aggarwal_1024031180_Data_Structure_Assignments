#include <iostream>
using namespace std;
class sparseMatrix{
    int **A;
    int m,n;
    int maxNonZero;
    int count;
    void insert(int idx){
        for (int i=count;i>idx;i++){
            for (int j=0;j<3;j++) A[i][j]=A[i-1][j];
        }
        count++;
    }
    void addAndCopy(sparseMatrix* source1,int srow1,sparseMatrix* source2,int srow2, sparseMatrix* dest,int drow){
        dest->A[drow][0]=source1->A[srow1][0];dest->A[drow][1]=source1->A[srow1][1];dest->A[drow][2]=source1->A[srow1][2]+source2->A[srow2][2];
        dest->count++;
    }
    void copy(sparseMatrix* source,int srow, int drow, sparseMatrix* dest){
        dest->A[drow][0]=source->A[srow][0];dest->A[drow][1]=source->A[srow][1];dest->A[drow][2]=source->A[srow][2];
        dest->count++;
    }
    void swapNum(int &a,int &b){
        a=a+b;b=a-b;a=a-b;
    }
    void swapRow(int arr1[],int arr2[]){
        for (int i=0;i<3;i++){
            arr1[i]=arr1[i]+arr2[i];arr2[i]=arr1[i]-arr2[i];arr1[i]=arr1[i]-arr2[i];
        }
    }
    void sort(sparseMatrix *ob3){
        for (int i=0;i<ob3->count;i++){
            bool flag = false;
            for (int j=0;j<ob3->count-i-1;j++){
                if (ob3->A[j][0]>ob3->A[j+1][0]||(ob3->A[j][0]==ob3->A[j+1][0]&&ob3->A[j][1]>ob3->A[j+1][1])){
                    swapRow(ob3->A[j],ob3->A[j+1]);
                }
            }
        }
    }
    public:
    sparseMatrix(int rows, int cols, int maxNonZero) {
        this->m = rows;
        this->n = cols;
        this->maxNonZero = maxNonZero;
        count = 0;

        A = new int*[maxNonZero];
        for (int i = 0; i < maxNonZero; i++)
            A[i] = new int[3];  // row, col, value
    }
    sparseMatrix addition(sparseMatrix ob1, sparseMatrix ob2){
        sparseMatrix ob3(ob1.m,ob2.n,100);
        int l=0,k=0;
        while(k<ob1.count){
            if (l==ob2.count){
                copy(&ob1,k,ob3.count,&ob3);
                k++;
            }
            else if (ob1.A[k][0]==ob2.A[l][0]&&ob1.A[k][1]==ob2.A[l][1]){
                addAndCopy(&ob1,k,&ob2,l,&ob3,ob3.count);l++;k++;
            }
            else if (ob1.A[k][0]>ob2.A[l][0]||(ob1.A[k][0]==ob2.A[l][0]&&ob1.A[k][1]>ob2.A[l][1])){
                copy(&ob2,l,ob3.count,&ob3);
                l++;
            }
            else if (ob1.A[k][0]<ob2.A[l][0]||(ob1.A[k][0]==ob2.A[l][0]&&ob1.A[k][1]<ob2.A[l][1])){
                copy(&ob1,k,ob3.count,&ob3);
                k++;
            }
            
        }
        while(l<ob2.count){
            copy(&ob2,l,ob3.count,&ob3);
            l++;
        }
        return ob3;
    }

    void set(int i,int j,int x){
        int k=0;
        while (k<count){
            if (i<A[k][0]||(i==A[k][0]&&j<A[k][1])){
            A[k][0]=i;A[k][1]=j;A[k][2]=x;
            return;   
            }
            if (i==A[k][0]&&j==A[k][1]){
                A[k][2]=x;return;
            }
            k++;
        }
    A[count][0] = i;
    A[count][1] = j;
    A[count][2] = x;
    count++;
    }
    sparseMatrix transpose(sparseMatrix ob1){
        for (int i=0;i<ob1.count;i++){
            swapNum(ob1.A[i][0],ob1.A[i][1]);
        }
        sort(&ob1);
        return ob1;
    }
    sparseMatrix multiplication(sparseMatrix ob1, sparseMatrix ob3){
        //     if (ob1.n != ob3.m) {
        //     cout << "Multiplication not possible!" << endl;
        //     return sparseMatrix(0,0,0);
        // }
        sparseMatrix ob2(ob3.n,ob3.m,100);
        sparseMatrix mat(ob1.m,ob3.n,100);
        ob2 = transpose(ob3);
        int row1=0,row2=0,backTrackrow1=0;
        for (int i=0;i<ob1.count;i++){
            while (ob1.A[row1][0]!=i&&row1<ob1.m){row1++;}
            if (row1!=ob1.m) backTrackrow1=row1;
            for (int j=0;j<ob2.count;j++){
                int sum = 0;
                row1=backTrackrow1;
                row2=0;
                while (ob1.A[row1][0]==i&&ob2.A[row2][0]==j){
                    if (ob1.A[row1][1]==ob2.A[row2][0]){
                        if (ob1.A[row1][1]<ob2.A[row2][1])row1++;
                        else if (ob2.A[row2][1]<ob1.A[row1][1])row2++;
                        else {sum=sum+ob1.A[row1][2]*ob2.A[row2][2];row1++;row2++;} 
                    }
                mat.set(i,j,sum);
                }
            }
        }
        return mat;
    }
    
    void display(){
        int k=0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (A[k][0]==i&&A[k][1]==j&&k<count) {cout<<A[k][2]<<" ";k++;}
                else cout<<"0 ";
            }
            cout<<endl;
        }
    }
};
int main(){
    // sparseMatrix sp1(4,4,5);
    // sp1.set(0,1,3); sp1.set(0,3,5);
    // sp1.set(2,0,1); sp1.set(2,1,2);
    // sp1.set(3,3,10);

    // sparseMatrix sp2(4,4,5);
    // sp2.set(0,1,4); sp2.set(1,2,7);
    // sp2.set(2,1,5); sp2.set(3,3,6);

    // cout << "Matrix 1:" << endl;
    // sp1.display();
    // cout << "\nMatrix 2:" << endl;
    // sp2.display();

    // cout << "\nMatrix Sum:" << endl;
    // sparseMatrix sp3 = sp1.addition(sp1, sp2);
    // sp3.display();

    // cout << "\nTranspose of Matrix 1:" << endl;
    // sparseMatrix spT = sp1.transpose(sp1); 
    // spT.display();

    //Multiplication
    sparseMatrix ob10(4,4,5), ob11(4,4,5);
    ob10.set(0,1,10);
    ob10.set(0,3,12);
    ob10.set(2,3,5);
    ob10.set(3,0,15);ob10.set(3,1,12);

    ob11.set(0,2,8);
    ob11.set(1,3,23);
    ob11.set(2,2,9);
    ob11.set(3,0,20);ob11.set(3,1,25);
    cout<<"\nMultiplication of two Matrices:"<<endl;
    sparseMatrix sp10 = ob10.multiplication(ob10,ob11);
    sp10.display();

    return 0;
}