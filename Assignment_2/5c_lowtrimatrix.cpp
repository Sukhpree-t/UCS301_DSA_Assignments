#include<iostream>
using namespace std;
int main() {
    int n;
cout<<"Enter size of array"<<endl;
cin>>n;
int size=((n*(n+1))/2);
int a[size];
cout<<"Enter elements"<<endl;
for(int i=0;i<size;i++){
cin>>a[i];
}
int k=0;
cout<<"Lower Triangular Matrix is as follows"<<endl;
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
if(i>=j){
cout<<a[k]<<" ";
k++;
}
else{
cout<<"0"<<" ";
}
}
cout<<endl;
}
return 0;
}