#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularList {
    Node* head;
    Node* tail;
    public:
    CircularList() {
        head=tail=NULL;
    }

    void insert_at_head(int val) {
        Node* newNode = new Node(val);
        if(head==NULL) {
            head = tail = newNode;
            tail->next = head;
        }
        else {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }

    void insert_at_tail(int val) {
        Node* newNode = new Node(val);
        if(head==NULL) {
            head= tail= newNode;
            tail->next = head;
        }
        else {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    } 

    void printll() {
        if(head==NULL) {
            cout<<"List is Empty"<<endl;
        }
        cout<<head->data<<" - > ";
        Node* temp = head->next;
        while(temp!=head){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<temp->data<<endl;
    }

    void delete_at_head() {
        if(head==NULL) {
            return;
        }
        else if(head==tail) {
            delete head;
            head = tail = NULL;
        }
        else {
            Node* temp = head;
            head = head->next;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }

    void delete_at_tail() {
        if(head==NULL) {
            return;
        }
        else if(head==tail) {
            delete head;
            head = tail = NULL;
        }
        else {
            Node* temp = tail;
            Node* prev = head;

            while(prev->next != tail) {
                prev = prev->next;
            }
            tail = prev;
            tail->next = head;

            temp->next = NULL;
            delete temp;
        }
    }
};

int main() {
    CircularList cll;

    cll.insert_at_head(2);
    cll.insert_at_head(4);

    cll.insert_at_tail(3);
    cll.printll();
}