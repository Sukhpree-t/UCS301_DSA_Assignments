#include<iostream>
using namespace std;

int main() {
    int rows = 3, cols = 2;
    int matrix[3][2] = {{1, 2}, {3, 4}, {5, 6}};
    int transpose[2][3];
    
    // Find transpose
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
    
    // Print original matrix
    cout << "Original Matrix:" << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    // Print transpose matrix
    cout << "Transpose Matrix:" << endl;
    for(int i = 0; i < cols; i++) {
        for(int j = 0; j < rows; j++) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}