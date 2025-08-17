#include<iostream>
using namespace std;
int main(){
int n;
int a[n];
cout<<"Enter the size of array"<<endl;
cin>>n;
cout<<"Enter the diagonal elements"<<endl;
for(int i=0;i<n;i++){
cin>>a[i];
}
cout<<"Diagonal Matrix is as follows:"<<endl;
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
if(i==j){
cout<<a[i]<<" ";
}
else{
cout<<"0 ";
}
}
cout<<endl;
}
return 0;
}