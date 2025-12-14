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
        }else if (key < current_node->data)
			return	Search(current_node->left, key);
		else
			return Search(current_node->right, key);
    }

    void deleteNode(int key){
     //search for the node
     Node* parent = nullptr;
     Node* current = root;
     current = Search(current, key);

     //design 3 cases
     if(current->left == nullptr && current->right == nullptr)/*case 1 - node has no children*/
     { 
         if (key == root->data)
         {
             delete root; //heap
             root = nullptr; //stack
         }
         //delete current
         delete current;
         //update parent's connection
         if (key < parent->data)
             parent->left = nullptr;
         else
             parent->right;
     }
     else if (current->left == nullptr || current->right == nullptr)/*case 2 - node has 1 child*/
     {
         //define the child
         Node* child;
         if (current->left != nullptr) child = current->left;
         else child = current->right;
         
         if (key == root->data)
         {
             delete root; //heap
             root = child; //stack
         }
         //delete current
         delete current;

         //connect parent with child
         if (child->data < parent->data) parent->left = child;
         else parent->right = child;
     }
     else if (current->left != nullptr && current->right != nullptr)/*case 3 - node has 2 children*/
     {
         //define two pointers
         Node* succ = current;
         Node* temp = current->right;
         //reach the successor
         while (temp != nullptr)
         {
             succ = temp;
             temp = temp->left;
         }
         //update the current's data with the successor's key
         current->data = succ->data;
         //delete successor
         deleteNode(succ->data);

     }
 }
};


int main(){

    return 0;
}