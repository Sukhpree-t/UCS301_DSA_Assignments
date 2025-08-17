#include<iostream>
using namespace std;
int main(){
int n;
cout<<"Enter the size of array"<<endl;
cin>>n;
int size=(n*(n+1))/2;
int a[size];
cout<<"Enter the elements of array"<<endl;
for(int i=0;i<size;i++){
cin>>a[i];
}
int b[n][n];
int k=0;
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
if(i<=j){
b[i][j]=a[k];
k++;
}
}
}
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
if(i>j){
b[i][j]=b[j][i];
}
}
}
cout<<"Symmetric Matrix is as follows"<<endl;
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
cout<<b[i][j]<<" ";
}
cout<<endl;
}
return 0;
}