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

void bubbleSort(int arr[],int size){
    bool flag;
    for (int i=0;i<size;i++){
        flag=false;
        for (int j=0;j<size-i-1;j++){
            if (arr[j]>arr[j+1]) {int temp=arr[j]; arr[j]=arr[j+1];arr[j+1]=temp;flag=true;}
        }
        if (!flag) break;
    }
}

int countDistinctElements(int arr[],int size){
    bubbleSort(arr,size);
    if (size==0) return 0;
    int count=1;
    for (int i=1;i<size;i++){
        if(arr[i]!=arr[i-1]) {count++;}
    }return count;
}

int main(){
    int *arr,size,num;
    create(&arr,size);
    num=countDistinctElements(arr,size);
    cout<<"Number of distinct elements are:"<<num<<endl;

    delete [] arr;

    return 0;
}