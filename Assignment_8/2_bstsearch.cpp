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

Node* insert(Node* root, int val) {
    if(root==NULL) {
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
    if(root == NULL) {
        return false;
    }
    if(root->data == key) {
        return true;
    }
    if(root->data >key) {
        return search(root->left, key);
    }
    else {
        return search(root->right, key);
    }
}

Node* rightmostinleft(Node* root) {
    Node* ans;
    while(root != NULL) {
        ans = root;
        root = root->right;
    }
    return ans;
}
Node* leftmostinright(Node*root) {
    Node* ans;
    while(root != NULL) {
        ans = root;
        root = root->left;
    }
    return ans;
}

vector<int> getPredSucc(Node* root, int key) {
    Node* curr = root;
    Node* succ = NULL;
    Node* pred = NULL;

    while(curr!=NULL) {
    if(key < curr->data) {
        succ = curr;
        curr = curr->left;
    }
    else if(key > curr->data) {
        pred = curr;
        curr = curr->right;
    }

    else {
        if(curr->left!=NULL) {
        pred = rightmostinleft(curr->left);
        }
        if(curr->right!=NULL) {
        succ = leftmostinright(curr->right);
        }
        break;
    }
    }
    return {pred->data, succ->data};
}

void inorder(Node* root, vector<int>& sorted_inorder) {
    
    if (root == nullptr) return;

    inorder(root->left, sorted_inorder);

    sorted_inorder.push_back(root->data);

    inorder(root->right, sorted_inorder);
}


int maxValue(Node* root) {
    if (root == nullptr) return -1;

    vector<int> sorted_inorder;
    inorder(root, sorted_inorder);

    return sorted_inorder.back();
}

int minValue(Node* root) {
    if (root == nullptr) return -1;

    vector<int> sorted_inorder;
    inorder(root, sorted_inorder);

    return sorted_inorder.front();
}

int main() {
    Node* root = new Node(6);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    cout<<endl;

    cout<<search(root, 5)<<endl;

    int key = 6;
    vector<int> ans = getPredSucc(root, key);
    cout<<"Predecessor: "<<ans[0]<<" Successor: "<<ans[1]<<endl;
    cout<<"Max value: "<<maxValue(root)<<endl;
    cout<<"Min value: "<<minValue(root)<<endl;

    return 0;
}