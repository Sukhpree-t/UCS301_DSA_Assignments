#include<iostream>
#include<cstring>
using namespace std;

#define MAX 100
char stackArr[MAX];
int top = -1;

bool isEmpty() {
    return (top == -1);
}

bool isFull() {
    return (top == MAX-1);
}

void push(char x) {
    if(isFull()) {
        cout<<"Stack Overflow! Cannot push"<<endl;
    }
    else {
        stackArr[++top] = x;
    }
}

char pop() {
    if(isEmpty()) {
        cout << "Stack is empty" << endl;
        return '\0';
    }
    else {
        return (stackArr[top--]);
    }
}

int main() {
    char str[MAX];
    cout << "Enter string : ";
    cin >> str;

    for(int i = 0; i < strlen(str); i++) {
        push(str[i]);
    }

    cout << "Reversed string\n";

    while(!isEmpty()) {
        cout << pop();
    }
    cout << endl;

    return 0;


}