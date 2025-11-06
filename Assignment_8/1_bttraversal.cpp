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

static int idx =-1;
Node* buildTree(vector<int> preorder) {
    idx++;

    if (idx >= preorder.size()) return NULL;

    if(preorder[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;

}

//Preorder Traversal

void preOrder(Node* root) {
    if(root == NULL) {
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

//Inorder Traversal

void inOrder(Node* root) {
    if(root==NULL) {
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(Node* root) {
    if(root==NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";

}

int main() {
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    // vector<int> preorder = {41,16,53,-1,25,46,55,-1,-1,42,-1,-1,-1};


    Node* root = buildTree(preorder);

    preOrder(root);
    cout<<endl;

    inOrder(root);
    cout<<endl;

    postOrder(root);
    cout<<endl;

    return 0;
}