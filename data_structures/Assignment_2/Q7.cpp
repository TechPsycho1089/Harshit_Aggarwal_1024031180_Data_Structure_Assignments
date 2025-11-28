#include <iostream>
using namespace std;
void create(int **arr,int &size){
    cout<<"What is the size of the array. ";cin>>size;
    *arr = new int [size];
    if (size<0) {cout<<"Invalid array size. Try again.\n";return;}
    cout<<"Enter the elements:"<<endl;
    for (int i=0;i<size;i++){
        cin>>(*arr)[i];
    }
}
int countInversions(int arr[],int size){
    int count=0;
    for (int i=0;i<size;i++){
        for (int j=i+1;j<size;j++){
            if (arr[i]>arr[j]) count++;
        }
    }
    return count;
}

int main(){
    int *arr,size,num;
    create(&arr,size);
    num = countInversions(arr,size);
    cout<<"Number of the inversion in the array is "<<num<<endl;
    delete [] arr;
    return 0;
}