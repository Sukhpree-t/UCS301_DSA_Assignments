#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
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

     void pushfront(int val) {
        Node* newNode = new Node(val);
        if(isEmpty()) {
            head = tail = newNode;
        } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        }
        return;
     }

     void pushback(int val) {
        Node* newNode = new Node(val);
        if(isEmpty()) {
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        return;
     }

    void pushAftervalue(int val, int num) {
        Node* newNode = new Node(num);
        Node* temp = head;
        while(temp!=NULL) {
            if(temp->data == val) {
                newNode->next = temp->next;
                newNode->prev = temp;
                if(temp->next!=NULL) {
                    temp->next->prev = newNode;
                }
                temp->next = newNode;
                return;
            }
            temp= temp->next;
        }
        cout<<val<<" : Value not found in the list"<<endl;
    }

     void popfront() {
        if(isEmpty()) {
            cout<<"List is Empty"<<endl;
        }
        else {
            Node* temp = head;
            head = head->next;
            head->prev = NULL;
            temp->next = NULL;
            delete temp;
        }
     }

     void popback() {
        if(isEmpty()) {
            cout<<"List is Empty"<<endl;
        }
        else {
            Node* curr = head;
            while(curr->next != NULL) {
                curr = curr->next;
            }
            if(curr == head) {
                head = tail = NULL;
            }
            else {
            tail = curr->prev;
            curr->prev->next = NULL;
            curr->prev = NULL;
            }
            delete curr;
        }
     }

    void popVal(int val) {
        Node* temp = head;
        while(temp!=NULL) {
            if(temp->data == val){
                if(temp == head) {
                    popfront();
                }
                else if(temp->next==NULL) {
                    popback();
                }
                else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete temp;
                }
                
                return;
            }
            temp = temp->next;
        }
    }

     void printll() {
        Node* temp = head;
        while(temp != NULL) {
            cout<< temp->data <<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
     }

};

int main() {
    DoublyList dll;
    dll.pushfront(2);
    dll.pushfront(4);
    dll.pushback(5);
    dll.printll();
    dll.pushAftervalue(5,6);
    dll.printll();
    dll.popVal(6);
    dll.printll();

    return 0;
}