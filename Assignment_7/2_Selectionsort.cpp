#include<iostream>
using namespace std;

void SelectionSort(int *arr, int n) {
    for(int i=0; i<n; i++) {
        int sId = i;
        for(int j=i+1; j<n; j++) {
            if(arr[j]<arr[sId]) {
                sId = j;
            }
        }
        swap(arr[i],arr[sId]);
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

    SelectionSort(arr,5);
    print(arr);

    return 0;
}