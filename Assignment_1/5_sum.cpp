#include<iostream>
using namespace std;

int main() {
    const int rows = 3;
    const int cols = 3;
    int arr[rows][cols] = {{1, 2, 3},
                           {4, 5, 6}, 
                           {7, 8, 9}};

    for (int i=0; i<rows; i++) {
        int sumrows = 0;
        for(int j=0; j<cols; j++) {
            sumrows+= arr[i][j];
        }
        cout<< "Sum of row"<<i<<" : "<<sumrows<<endl;
    }
    for (int i=0; i<rows; i++) {
        int sumcols = 0;
        for(int j=0; j<cols; j++) {
            sumcols+= arr[j][i];
        }
        cout<< "Sum of columns"<<i<<" : "<<sumcols<<endl;
    }
}