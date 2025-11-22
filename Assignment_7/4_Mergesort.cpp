#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr, int st, int mid, int end) {
    vector<int> temp;
    int i=st;
    int j=mid+1;
    while(i<=mid && j<=end)
    if(arr[i]<=arr[j]) {
        temp.push_back(arr[i]);
        i++;
    }
    else {
        temp.push_back(arr[j]);
        j++;
    }

    while(i<=mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end) {
        temp.push_back(arr[j]);
        j++;
    }

    for(int idx=0; idx<temp.size(); idx++) {
        arr[st+idx] = temp[idx];
    }
}

void MergeSort(vector<int> &arr, int st, int end) {
    if(st<end) {
    int mid = st+(end-st)/2;
    //lefthalf
    MergeSort(arr, st, mid);
    //right half
    MergeSort(arr, mid+1, end);

    merge(arr, st, mid, end);
    }
    
}

void print(vector<int> arr) {
    for(int i=0; i<5; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    vector<int> arr = {8,1,7,5,2};
    print(arr);

    MergeSort(arr,0,arr.size()-1);
    print(arr);

    return 0;
}

