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

class List{
    Node* head;
    Node* tail;
    public:
        List(){
            head=tail=NULL;
        }
        void push_front(int val) {
            Node* newNode = new Node(val);
            if(head==NULL) {
                head=tail=newNode;
                return;
            }
            else {
                newNode->next = head;
                head = newNode;
            }
        }

        void printll() {
            Node* temp = head;
            while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }

        Node* middleNode() {
            Node* slow=head;
            Node* fast=head;

            while(fast != NULL && fast->next != NULL) {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }
};
int main() {
    List l1;

    l1.push_front(2);
    l1.push_front(4);
    l1.push_front(6);
    l1.push_front(8);
    // l1.push_front(10);

    l1.printll();

    Node* middle = l1.middleNode();
    cout<<"Middle Node is : "<<middle<<endl;
    cout<<"Middle Node is : "<<middle->data<<endl;

    return 0;
}