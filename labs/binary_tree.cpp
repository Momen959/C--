#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left,* right;

    Node(int value){
        data = value;
        left = right = nullptr;
    }
};

class BinaryTree{
    //root for the whole tree
    Node* root;

    BinaryTree(){
        root = nullptr;
    }

    Node* insert(Node* current_node, int item){
        //use current_node pointer to track subtree roots
        if(current_node == nullptr){
            Node* newnode = new Node(item);
            current_node = newnode;
        }else if(item <= current_node->data){
            current_node->left = insert(current_node->left, item);
        }else{
            current_node->right = insert(current_node->right, item);
        }
        return current_node;
    }
    
    void insert(int item){
        root = insert(root, item);
    }
    //root -> left -> right
    void preorder(Node* current_node){
        if(current_node == nullptr){
            return;
        }
        cout << current_node->data << "\t";
        preorder(current_node->left);
        preorder(current_node->right);
    }
    //left -> root -> right
    void inorder(Node* current_node){
        if(current_node == nullptr){
            return;
        }
        inorder(current_node->left);
        cout << current_node->data << "\t";
        inorder(current_node->right);
    }
    //left -> right -> root
    void postorder(Node* current_node){
        if(current_node == nullptr){
            return;
        }
        cout << current_node->data << "\t";
        postorder(current_node->left);
        postorder(current_node->right);
    }
    Node* Search(Node* current_node, int key){
        if(current_node == nullptr){
            return ;
        }else if(current_node->data == key){
            return current_node;
        }
    }
};


int main(){

    return 0;
}