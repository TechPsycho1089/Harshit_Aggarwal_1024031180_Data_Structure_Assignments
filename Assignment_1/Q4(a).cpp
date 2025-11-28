#include <iostream>
using namespace std;
void display(int array[],int size){
    for (int i = 0;i<size;i++){
        cout<<array[i]<<"\n";
    }    
}
int* reverse(int arr[],int size){
    int* newArr=new int [size],j=0;
    for (int i=size-1;i>=0;i--){
        newArr[j++]=arr[i];
    }
    return newArr;
}
int main(){
    int size=10;int* ptr;
    int arr[size]={1,2,3,4,5,6,7,8,9,10};
    ptr = reverse(arr,size);
    display(ptr,10);
    delete[] ptr;
    return 0;
}