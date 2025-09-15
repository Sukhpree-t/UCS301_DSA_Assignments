#include<iostream>
#include<queue>
using namespace std;

int main() {
    queue<int> q;

    q.push(2);
    q.push(4);
    q.push(6);

    cout<<"Size of queue : "<<q.size()<<endl;

    q.pop();
    cout<<"Size of queue : "<<q.size()<<endl;

    if(q.empty()) {
        cout<<"Queue is empty"<<endl;
    }
    else {
        cout<<"Queue is not empty"<<endl;
    }
}