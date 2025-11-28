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
void insert(int arr[],int &size){
    int idx,elem; cout<<"Enter the index for element to be inserted.";cin>>idx;
    if (idx>size||idx<0) {cout<<"Error: Index out of range.\n";return;}
    cout<<"Enter the element to be inserted. ";cin>>elem;
    for (int i=size;i>idx;i--) arr[i]=arr[i-1];
    arr[idx]=elem;
    size++;
}
void elemDelete(int arr[],int &size){
    int idx;cout<<"Enter the index of the element that is to be deleted.";cin>>idx;
    if (idx>size-1||idx<0) {cout<<"Error: Index out of range.\n"; return;}
    for (int i=idx;i<=size-2;i++) arr[i]=arr[i+1];
    size--;
}
void linearSearch(int* arr,int &size){
    int elem;cout<<"Which element do you want to find? ";cin>>elem;
    for (int i=0;i<size;i++) if (arr[i]==elem) {cout<<"Element you want is at index: "<<i<<endl;return;}
    cout<<"Element not found.";
}
int main() {
    int arr[100],operation, size=0; // maximum size of the array is predefined.
    while (true){
        cout<<"-------MENU-------\n";
        cout<<"1. Create\n";
        cout<<"2. Display\n";
        cout<<"3. Insert\n";
        cout<<"4. Delete\n";
        cout<<"5. Linear Search\n";
        cout<<"6. Exit\n"<<"choose: ";
        cin>>operation;
        switch(operation){
            case 1: create(arr,size);break;
            case 2: if (size==0){cout<<"Array is empty.Try again.\n";break;} display(arr,size);break;
            case 3: if (size==100){cout<<"Array is full. Try again.\n";break;}insert(arr,size);break;
            case 4: if (size==0){cout<<"Array is empty.Try again.\n";break;} elemDelete(arr,size);break;
            case 5: if (size==0){cout<<"Array is empty.Try again.\n";break;} linearSearch(arr,size);break;
            case 6: cout<<"Exiting program..."; return 0;
        }
    }
    return 0;
}