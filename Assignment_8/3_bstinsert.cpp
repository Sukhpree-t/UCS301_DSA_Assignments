#include<iostream>
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

Node* insert(Node* root, int val) {
    if(root == NULL) {
        return new Node(val);
    }

    if(val<root->data) {
    root->left = insert(root->left, val);
    }
    else {
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

bool search(Node* root, int key) {
    if(root==NULL) {
        return false;
    }
    if(root->data == key) {
        return true;
    }
    if(root->data >key) {
        return search(root-> left, key);
    }
    else {
        return search(root->right, key);
    }
}

Node* getInorderSuccessor(Node* root) {
    while(root != NULL &&   root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* delNode(Node* root, int key) {
    if(root==NULL) {
        return NULL;
    }

    if(key > root->data) {
        root->right = delNode(root->right, key);
    }
    else if(key < root->data) {
        root->left = delNode(root->left, key);
    }
    else {
        if(root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node* SI = getInorderSuccessor(root->right);
            root->data = SI->data;
            root->right = delNode(root->right, SI->data);
        }
    }
    return root;
}

int maxdepth(Node* root) {
    if(root==NULL) {
        return 0;
    }
    int lheight = maxdepth(root->left);
    int rheight = maxdepth(root->right);
    return (max(lheight, rheight) + 1);
}

int mindepth(Node* root) {
    if(root==NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    int lheight = mindepth(root->left);
    int rheight = mindepth(root->right);
    return (min(lheight, rheight) + 1);
}

void inOrder(Node* root) {
    if(root==NULL) {
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main() {
    vector<int> arr = {3,2,1,5,6,4};
    Node* root = buildBST(arr);
    
    cout<<"Before: "<<endl;
    inOrder(root);
    cout<<endl;

    cout<<search(root, 8)<<endl;

    cout<<"After: "<<endl;
    delNode(root, 6);
    inOrder(root);
    cout<<endl;

    cout<<"Maximum depth of BST : "<<maxdepth(root)<<endl;
    cout<<"Minimum depth of BST : "<<mindepth(root)<<endl;

    return 0;
}