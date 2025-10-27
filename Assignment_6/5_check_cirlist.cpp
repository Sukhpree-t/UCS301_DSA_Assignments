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

class LinkedList {
    Node* head;
    
    public:
    LinkedList() {
        head = NULL;
    }
    
    void pushback(int val) {
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    void makeCircular() {
        if(head == NULL) return;
        
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = head; 
    }
        bool isCircular() {
        if(head == NULL) {
            return false;  
        }
        
        Node* temp = head->next;
        
        while(temp != NULL && temp != head) {
            temp = temp->next;
        }
        
        return (temp == head);
    }
    
    bool isCircularFloyd() {
        if(head == NULL) {
            return false;
        }
        
        Node* slow = head;
        Node* fast = head;
        
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast) {
                return true;  
            }
        }
        
        return false;
    }
    
    void print() {
        if(head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        
        Node* temp = head;
        int count = 0;
        cout << "List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
            count++;
            if(count > 20) {  
                cout << "... (circular)" << endl;
                return;
            }
        } while(temp != NULL && temp != head);
        
        if(temp == head) {
            cout << "(back to head)" << endl;
        } else {
            cout << "NULL" << endl;
        }
    }
};

int main() {
    LinkedList ll;
    
    cout << "Test 1: Normal Linked List" << endl;
    ll.pushback(1);
    ll.pushback(2);
    ll.pushback(3);
    ll.pushback(4);
    ll.pushback(5);
    
    ll.print();
    
    if(ll.isCircular()) {
        cout << "The linked list is CIRCULAR" << endl;
    } else {
        cout << "The linked list is NOT CIRCULAR" << endl;
    }
    
    cout << "\n";
    
    cout << "Test 2: After making it circular" << endl;
    ll.makeCircular();
    
    ll.print();
    
    if(ll.isCircular()) {
        cout << "The linked list is CIRCULAR" << endl;
    } else {
        cout << "The linked list is NOT CIRCULAR" << endl;
    }
    
    cout << "\nUsing Floyd's algorithm: ";
    if(ll.isCircularFloyd()) {
        cout << "The linked list is CIRCULAR" << endl;
    } else {
        cout << "The linked list is NOT CIRCULAR" << endl;
    }
    
    return 0;
}