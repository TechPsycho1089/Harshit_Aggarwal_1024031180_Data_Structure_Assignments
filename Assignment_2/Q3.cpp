#include <iostream>
using namespace std;
int findMissingLinear(int* arr,int size){
    for (int i=0;i<size-1;i++){    
    if (i+1!=arr[i]){
        return i+1;
    }
    }
}

int findMissingBinary(int array[],int size){
    int l = 0, u = size-1;
    while (u>=l){
        int mid = l + (u-l)/2;
        if(mid==array[mid]-1){
            l = mid + 1;
        }else{
            u = mid - 1;
        }
    }
    return l+1;
}
int main() {
    int arr[8] = {1, 2, 3, 5, 6, 7, 8, 9}; // missing 5
    int n = 9; // array should contain 1..9

    cout << "Missing (Linear): " << findMissingLinear(arr, n) << endl;
    cout << "Missing (Binary): " << findMissingBinary(arr, n) << endl;

    return 0;
}