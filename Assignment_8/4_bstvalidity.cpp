#include<iostream>
#include<climits>
#include<vector>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node(int val) {
            data = val;
            left = right = NULL;
        }
};

bool helper(Node* root, Node* min, Node* max) {
    if(root==NULL) {
        return true;
    }
    if(min!=NULL && root->data <= min->data) {
        return false;
    }
    if(max!=NULL && root->data >= max->data) {
        return false;
    }

    return helper(root->left, min, root) && helper(root->right, root, max);
}

bool isValidBST(Node* root) {
    return helper(root, NULL, NULL);
}

Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }
    
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    
    return root;
}

Node* buildBST(vector<int> arr) {
    Node* root = NULL;

    for(int val : arr) {
        root = insert(root, val);
    }
    return root;
}

Node* buildInvalidBST(vector<int> &arr, int n) {
    if (n == 0) return NULL;
    
    Node* root = new Node(arr[0]);
    for (int i = 1; i < n; i++) {
        Node* temp = root;
        if (i % 2 == 1) {
            while (temp->left != NULL) temp = temp->left;
            temp->left = new Node(arr[i]);
        } else {
            while (temp->right != NULL) temp = temp->right;
            temp->right = new Node(arr[i]);
        }
    }
    return root;
}

int main() {
    vector<int> arr1 = {3,2,1,5,6,4};
    int n1 = arr1.size(); 
    Node* root1 = buildBST(arr1);
    
    cout << "Tree 1 (from array): ";
    for (int i = 0; i < n1; i++) cout << arr1[i] << " ";
    cout << "\nIs " << (isValidBST(root1) ? "BST" : "NOT BST") << endl << endl;

    // Invalid BST from array
    vector<int> arr2 = {10, 12, 5, 15, 2};
    int n2 = arr2.size();
    Node* root2 = buildInvalidBST(arr2, n2);
    
    cout << "Tree 2 (invalid structure): ";
    for (int i = 0; i < n2; i++) cout << arr2[i] << " ";
    cout << "\nIs " << (isValidBST(root2) ? "BST" : "NOT BST") << endl;
    
    return 0;
}