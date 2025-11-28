#include <iostream>
using std::cout,std::cin,std::endl;
void display(int array[],int size){
    for (int i = 0;i<size;i++){
        cout<<array[i]<<" ";
    }    cout<<endl;
}
void linearSearch(int* arr,int size){
    int elem;cout<<"Which element do you want to find? ";cin>>elem;
    for (int i=0;i<size;i++) if (arr[i]==elem) {cout<<"Element you want is at index: "<<i<<endl;return;}
    cout<<"Element not found.";
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
void binarySearch(int array[],int size){
    int l = 0, u = size-1, num;
    cout<<"what number do you want to binary search? ";
    cin>>num;
    
    while (u>=l){
        int mid = l + (u-l)/2;
        if (array[mid] == num){
            cout<<"Index of the required number is "<<mid;
            return;
        }else if(array[mid]>num){
            u = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    cout<<"Number not found!";
}
int main(){
    int size;
    cout<<"What size of array do you want? ";
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    // binary_search(arr,size);
    bubbleSort(&arr[0],size);
    display(arr,size);
    binarySearch(arr,size);
    return 0;
}