#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node():data(0),left(nullptr),right(nullptr){}
    Node(int num):data(num),left(nullptr),right(nullptr){}
};
class BST{
    Node* root;
    void insert(Node* root, int num){
        if (!root)
            return = new root(num);
        if (num < root->data)
            root->left = insert(root->left,num);    
        else 
            root->right = insert(root->right,num);
    }

    void inorder_traversal(Node* root){
        if (!root) return;
        if (root->left) inorder_traversal(root->left);
        cout<<root->data<<",";
        if (root->right) inorder_traversal(root->right);
    }

    void preorder_traversal(Node* root){
        if (!root) return;
        cout<<root->data<<",";
        if (root->left) preorder_traversal(root->left);
        if (root->right) preorder_traversal(root->right);
    }

    void postorder_traversal(Node* root){
        if (!root) return;
        if (root->left) postorder_traversal(root->left);
        if (root->right) postorder_traversal(root->right);
        cout<<root->data<<",";
    }

    public:
    BST():root(nullptr){}

    void insert_node(int num){ insert(root,num); }

    void inorder(root){
        if (!root) 
            cout<<"Error: BST empty."<<endl;
        else
            inorder_traversal(root); 
    }
    
    void preorder(root){
        if (!root)
            cout<<"Error: BST empty."<<endl;
        else
            preorder_traversal(root); 
    }

    void postorder(root){
        if (!root) 
            cout<<"Error: BST empty."<<endl;
        else
            postorder_traversal(root); 
    }
};

int main(){

}