#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyList {
    Node* head;
    Node* tail;
    public:

    DoublyList() {
        head = tail = NULL;
    }
    
    bool isEmpty() {
        if(head==NULL) {
            return true;
        }
        return false;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if(isEmpty()) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if(isEmpty()) {
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() {
        if(isEmpty()) {
            cout<<"List is Empty"<<endl;
        }
        else {
            Node* temp = head;
            head = head->next;
            if(head != NULL) {
                head->prev = NULL;
            } else {
                // List becomes empty, so tail should also be NULL
                tail = NULL;
            }
            temp->next = NULL;
            delete temp;
        }
    }

    void pop_back() {
        if(isEmpty()) {
            cout<<"List is Empty"<<endl;
        }
        else {
            Node* temp = tail;
            tail = tail->prev;
            if(tail != NULL) {
                tail->next = NULL;
            } else {
                // List becomes empty, so head should also be NULL
                head = NULL;
            }
            temp->prev = NULL;
            delete temp;
        }
    }

    void printll() {
        Node* temp = head;
        while(temp != NULL) {
            cout<< temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main() {
    DoublyList dll;

    dll.push_front(2);
    dll.push_front(4);
    dll.push_front(6);

    dll.printll();

    dll.push_back(8);

    dll.printll();

    dll.pop_front();
    dll.printll();

    dll.pop_back();
    dll.pop_back();
    // dll.pop_back();
    dll.printll();

    dll.pop_front();
    dll.printll();

}