//quick sort

#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &arr, int l, int h){
  int pivot = arr[l];
  int i = l, j = h;
  while(i < j){
    do{
      i++;
    }while(arr[i] <= pivot);
    do{
      j--;
    }while(arr[j] > pivot);
    if(i < j){
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[l], arr[j]);
  return j;
}

void quickSort(vector<int> &arr, int l, int h){
  if(l < h){
    int j = partition(arr,l,h);
    quickSort(arr,l,j);
    quickSort(arr,j+1,h);
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

  quickSort(arr, 0, n);
  
  cout<<"Array after sorting : "<<endl;
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}