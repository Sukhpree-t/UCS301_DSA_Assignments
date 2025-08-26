#include<iostream> 
using namespace std;

#define MAX 5

int stack[MAX];
int top=-1;

bool isEmpty() {
    return (top== -1);
}

bool isFull() {
    return (top == MAX-1);
}

void push(int ele) {
    if(isFull()) {
        cout<<"Stack Overflow! Cannot push"<<endl;
    }
    else {
        top++;
        stack[top] = ele;
        cout<<"Pushed into stack."<<endl;
    }
}

void pop() {
    if(isEmpty()) {
        cout << "Stack is Empty!!" << endl;
    }
    else {
        cout << stack[top--] << "  popped from stack." <<endl;
    }
}

void display() {
    if(isEmpty()) {
        cout << "Stack is Empty!!"<<endl;
    }
    else {
        cout<< "Stack element (top to bottom)"<<endl;
        for(int i=top; i>=0; i--) {
        cout << stack[i] << " ";
    }
    cout<<endl;
    }    
}

void peek() {
    if(isEmpty()) {
        cout << "Stack is empty, nothing at top."<<endl;
    }
    else {
        cout << "Top element is : " <<stack[top] <<endl;
    }
}
int main() {
    int choice,value;

    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to push : ";
                cin >> value;
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                if (isEmpty())
                cout << "Stack is Empty." << endl;
            else
                cout << "Stack is not Empty." << endl;
            break;
        case 4:
            if (isFull())
                cout << "Stack is Full." << endl;
            else
                cout << "Stack is not Full." << endl;
            break;
        case 5:
            display();
            break;
        case 6:
            peek();
            break;
        case 7:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 7);
    return 0;
}
