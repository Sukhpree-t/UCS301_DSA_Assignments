#include<iostream>
using namespace std;

class Queue {
    int *arr;
    int front;
    int rear;
    int size;

public:
    Queue() {
        size = 100001;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    bool isempty() {
        if(front == rear) {
            return true;
        }
        else {
            return false;
        }
    }

    void enqueue(int data) {
        if(rear == size) {
            cout<<"Queue is FULL!!"<<endl;
        }
        else {
            arr[rear] = data;
            rear++;
        }
    }

    void dequeue() {
        if(isempty()) {
            cout <<"Queue is EMPTY!!"<<endl;
        }
        else {
            cout << "Dequeued element: " << arr[front] << endl;
            front++;

            if(front == rear) {
                front = 0;
                rear = 0;
            }
        }
    }

    void display() {
        cout<<"Size of Queue : "<<(rear - front)<<endl;
        cout<<"Queue elements: ";
        for(int i = front; i < rear; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        if(isempty()) {
            cout <<"Queue is EMPTY!!"<<endl;
        }
    }

};

int main() {
    Queue q;
    q.enqueue(2);
    q.enqueue(4);
    q.enqueue(6);
    q.enqueue(8);
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
}