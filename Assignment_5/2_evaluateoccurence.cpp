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
    
    int countOccurrences(int key) {
        int count = 0;
        Node* temp = head;
        
        while(temp != NULL) {
            if(temp->data == key) {
                count++;
            }
            temp = temp->next;
        }
        return count;
    }
    
    void deleteAllOccurrences(int key) {
        if(head == NULL) return;
        
        while(head != NULL && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        
        Node* current = head;
        while(current != NULL && current->next != NULL) {
            if(current->next->data == key) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next;
            }
        }
    }
    
    void print() {
        if(head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data;
            if(temp->next != NULL) {
                cout << "->";
            }
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList ll;
    
    ll.pushback(1);
    ll.pushback(2);
    ll.pushback(1);
    ll.pushback(2);
    ll.pushback(1);
    ll.pushback(3);
    ll.pushback(1);
    
    cout << "Original Linked List: ";
    ll.print();
    
    int key = 1;
    
    int count = ll.countOccurrences(key);
    cout << "Count of " << key << ": " << count << endl;
    
    ll.deleteAllOccurrences(key);
    
    cout << "Updated Linked List: ";
    ll.print();
    
    return 0;
}