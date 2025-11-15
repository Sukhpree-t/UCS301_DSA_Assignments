#include<iostream>
using namespace std;

void BubbleSort(int *arr, int n) {
    for(int i=0; i<n-1; i++) {
        bool swapped = false;
        for(int j=0; j<n-i-1; j++) {
            if(arr[j]>arr[j+1]) {
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped) {
            break;
        }
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

    BubbleSort(arr,5);
    print(arr);

    return 0;
}