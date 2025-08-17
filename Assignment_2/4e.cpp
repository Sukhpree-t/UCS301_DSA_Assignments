#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Enter an uppercase character: ";
    cin >> ch;

    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + 32; // Convert to lowercase
        cout << "Lowercase: " << ch << endl;
    } else {
        cout << "The entered character is not uppercase." << endl;
    }

    return 0;
}
