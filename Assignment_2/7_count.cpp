#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    double A[n];
    cout << "Enter " << n << " real numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int inversionCount = 0;

    // Check all pairs (i, j) where i < j
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] > A[j]) {
                inversionCount++;
            }
        }
    }

    cout << "Number of inversions: " << inversionCount << endl;

    return 0;
}
