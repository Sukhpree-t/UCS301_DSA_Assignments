#include<iostream>
using namespace std;

int main() {
    int arr[] = {1,2,2,3,4,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int arr2[n];
    int j=0;

    for(int i=0; i<n; i++) {
        if(i == n-1 || arr[i] != arr[i+1]) {
            arr2[j++] = arr[i];
        }
    }
    for(int i=0; i<j; i++) {
        cout<<arr2[i]<< " ";
    }
    cout<<endl; 
return 0;
}