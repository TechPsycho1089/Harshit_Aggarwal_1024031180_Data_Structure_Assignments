#include <iostream>
using namespace std;
void create(int arr[],int &size){
    cout<<"What is the size of the array. ";cin>>size;
    if (size>100||size<0) {cout<<"Invalid array size. Try again.\n";return;}
    for (int i=0;i<size;i++){
        cout<<"Enter the element.";cin>>arr[i];
    }
}
void display(int array[],int size){
    for (int i = 0;i<size;i++){
        cout<<array[i]<<"\n";
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
void remove(int arr[],int pos,int &size){
    for (int i=pos;i<size-1;i++) arr[i]=arr[i+1];
    size--;
}
//Method 1: Brute Force 1, Time: O(n^3)
void bruteForce1(int arr[],int &size){
    for (int i=0;i<size;i++){
        for (int j=i+1;j<size;j++){
            if (arr[i]==arr[j]){
            remove(arr,j,size);
            j--;
            }
        }
    }
}
//Method 2: Brute Force 2, time: O(n^2)
int bruteForce2(int arr[],int size,int newArr[]){
    int m=0;bool found;
    for (int i=0;i<size;i++){
        found = false;
        for(int j=0;j<m;j++){
            if (arr[i]==newArr[j]) found=true;break;
        }
        if (!found) newArr[m++]=arr[i];
    }
    return m;
}
//Method 3: sort approach1, time:O(n)
int removeDuplicateSort1(int arr[],int size,int newArr[]){
    bubbleSort(arr,size);
    int m=0;
    newArr[m++]=arr[0];
    for (int i=1;i<size;i++){
        if(arr[i]!=arr[i-1]) {newArr[m++]=arr[i];}
    }return m;
}
//Method 4: sort approach2,time: O(n)
int removeDuplicateSort2(int arr[],int size){
    bubbleSort(arr,size);int n=0;
    arr[n++]=arr[0];
        for (int j=1;j<size;j++){
            if (arr[j]!=arr[j-1]) arr[n++]=arr[j];
    }
    return n;
}

int main(){
    int arr[100],newArr[100], size;
    create(arr,size);
    size = removeDuplicateSort2(arr,size);
    display(arr,size);

    return 0;
}