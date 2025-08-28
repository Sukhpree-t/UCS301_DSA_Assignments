#include<iostream>
using namespace std;
int main(){
int row,col;
cout<<"Enter number of rows of array"<<endl;
cin>>row;
cout<<"Enter number of columns of array"<<endl;
cin>>col;
int arr[row][col];
cout<<"Enter elements of array"<<endl;
for(int i=0;i<row;i++){
for(int j=0;j<col;j++){
cin>>arr[i][j];
}
}
cout<<"Matrix is as follows"<<endl;
for(int i=0;i<row;i++){
for(int j=0;j<col;j++){
cout<<arr[i][j]<<" ";
}
cout<<endl;
}
for(int i=0;i<row;i++){
int row_min=arr[i][0],col_index=0;
for(int j=1;j<col;j++){
if(row_min>arr[i][j]){
row_min=arr[i][j];
col_index=j;
}
}
int k;
for(k=0;k<row;k++){
if(row_min<arr[k][col_index]){
break;
}
}
if(k==row){
cout<<"Saddle point is "<<row_min<<endl;
}
}
return 0;
}