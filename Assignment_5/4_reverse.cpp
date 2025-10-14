#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int val) {
            data = val;
            next = NULL;
        }
};

class List{
    Node* head;
    public:
    List() {
        head=NULL;
    }
    void push_front(int val) {
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    Node* reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        while(curr!=NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void printll() {
        Node* temp = head;
        while(temp!=NULL) {
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main() {
    List l1;
    l1.push_front(2);
    l1.push_front(4);
    l1.push_front(6);

    l1.printll();

    
    Node* temp = l1.reverse();
    while(temp!=NULL) {
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
    
    return 0;
}