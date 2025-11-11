#include<iostream>
using namespace std;

class MaxHeap {
    int * arr;
    int size;
    int total_size;
    public:
        MaxHeap(int n) {
            arr = new int[n];
            size = 0;
            total_size = n;
        }

        //insertion in heap array
        void insert(int val) {
            if(size == total_size) {
                cout<<"Heap is OVERFLOW!"<<endl;
                return;
            }
            arr[size] = val;
            int index = size;
            size ++;

            //compare array with its parents
            while(index>0 && arr[index] > arr[(index-1)/2]) {
                swap(arr[index],arr[(index-1)/2]);
                index = (index-1)/2;
            }
            cout<<arr[index]<<" is inserted into the heap\n";
        }

        void Heapify(int index) {
            int largest = index;
            int left = 2*index+1;
            int right = 2*index+2;

            if(left>0 && arr[left]>arr[largest]) {
                largest = left;
            }

            if(right>0 && arr[right]>arr[largest]) {
                largest = right;
            }

            if(largest!=index) {
                swap(arr[index],arr[largest]);
                Heapify(largest);
            }
        }

        void Delete() {
            if(size == 0) {
                cout<<"UNDERFLOW!"<<endl;
                return;
            }

            cout<<arr[0]<<"delete from the heap"<<endl;
            arr[0] = arr[size-1];
            size--;

            if(size==0) {
                return;
            }
            Heapify(0);
        }

        int getMax() {
            if (size == 0) {
                cout << "Heap is empty!\n";
                return -1;
            }
            return arr[0];
        }

        bool isEmpty() {
            return size == 0;
        }


        void print() {
            for(int i=0; i<size; i++) {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

int main() {
    MaxHeap H1(6);
    H1.insert(4);
    H1.insert(14);
    H1.insert(11);
    H1.print();

    H1.Delete();
    H1.print();


}