#include<iostream>
using namespace std;

int main() {
    int n=2;
    int m=2;
    int arr1[n][m] = {{1,2},{3,4}};
    int arr2[n][m] = {{5,6},{7,8}};
    int arr[n][m];
    //Input the size of the matrices
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr1[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr2[i][j];
        }
    }

    //Matrix multiplication
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            arr[i][j] = 0;
            for(int k = 0; k < m; k++) {
                arr[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    //Print the input matrices
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    // Print the result
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}