#include<iostream>
using namespace std;

void InsertionSort(int *arr, int n) {
    for(int i=1; i<n; i++) {
        int curr = arr[i];
        int prev = i-1;

        while(prev>=0 && arr[prev]>curr) {
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }
}

void print(int arr[]) {
    for(int i=0; i<5; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int arr[5] = {8,1,7,5,2};
    print(arr);

    InsertionSort(arr,5);
    print(arr);

    return 0;
}