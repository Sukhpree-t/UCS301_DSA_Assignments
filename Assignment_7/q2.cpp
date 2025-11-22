#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int> &arr, int n){
  for(int i=0; i<n/2; i++){
    int min = i;
    int max = i;
    for(int j = i+1; j<n-i; j++){
      if(arr[j] < arr[min]){
        min = j;
      }
      if(arr[j] > arr[max]){
        max = j;
      }
    }
    swap(arr[i], arr[min]);
    if(max == i){
      max = min;
    }
    swap(arr[n-i-1], arr[max]);
  }
}

int main(){
  int n;
  cout<<"Enter number of elements : ";
  cin>>n;
  vector<int> arr(n);
  cout<<"Enter elements : "<<endl;
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  cout<<"Initial array : "<<endl;
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;

  selectionSort(arr, n);
  
  cout<<"Array after sorting : "<<endl;
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  return 0;
}