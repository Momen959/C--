#include <iostream>
using namespace std;


class Queue {

    struct Node {
        int data;
        Node* next;
    };

    Node* front;   // first element
    Node* rear;    // last element

public:

    Queue() {
        front = NULL;
        rear = NULL;
    }

    // add at the rear (enqueue)
    void enqueue(int x) {
        Node* newnode = new Node;
        newnode->data = x;
        newnode->next = NULL;

        // empty queue
        if (rear == NULL) {
            front = newnode;
            rear = newnode;
            return;
        }

        rear->next = newnode;
        rear = newnode;
    }

    // remove from the front (dequeue)
    void dequeue() {
        if (front == NULL) return;

        Node* temp = front;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
    }

    // get the front element
    int peek() {
        if (front == NULL) return -1;
        return front->data;
    }

    // display all elements from front to rear
    void display() {
        Node* p = front;

        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

};


class Stack {

    struct Node {
        int data;
        Node* next;
    };

    Node* top;   // points to top of stack

public:

    Stack() {
        top = NULL;
    }

    // push at the top
    void push(int x) {
        Node* newnode = new Node;
        newnode->data = x;
        newnode->next = top; // new node before old top
        top = newnode;
    }

    // pop from the top
    void pop() {
        if (top == NULL) return;

        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // show the top element
    int peek() {
        if (top == NULL) return -1;
        return top->data;
    }

    // display all elements from top to bottom
    void display() {
        Node* p = top;

        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

};



class BinaryTree {

    struct Node {
        int data;
        Node* left;
        Node* right;
    };

    Node* root;

public:

    BinaryTree() {
        root = NULL;
    }

    // create a new node
    Node* makeNode(int x) {
        Node* newnode = new Node;
        newnode->data = x;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }

    // insert
    void insert(int x) {
        Node* newnode = makeNode(x);

        if (root == NULL) {
            root = newnode;
            return;
        }

        Node* p = root;
        Node* parent = NULL;

        while (p != NULL) {
            parent = p;

            if (x < p->data)
                p = p->left;
            else
                p = p->right;
        }

        if (x < parent->data)
            parent->left = newnode;
        else
            parent->right = newnode;
    }

    // search in BinaryTree
    bool search(int x) {
        Node* p = root;

        while (p != NULL) {
            if (p->data == x)
                return true;

            if (x < p->data)
                p = p->left;
            else
                p = p->right;
        }

        return false;
    }


    // delete a node by value
    Node* deleteNodeRec(Node* p, int x) {

        if (p == NULL) return NULL;

        if (x < p->data)
            p->left = deleteNodeRec(p->left, x);
        else if (x > p->data)
            p->right = deleteNodeRec(p->right, x);
        else {

            // no child
            if (p->left == NULL && p->right == NULL) {
                delete p;
                return NULL;
            }

            // one child (right)
            if (p->left == NULL) {
                Node* temp = p->right;
                delete p;
                return temp;
            }

            // one child (left)
            if (p->right == NULL) {
                Node* temp = p->left;
                delete p;
                return temp;
            }

            // two children
            Node* temp = findMin(p->right);
            p->data = temp->data;
            p->right = deleteNodeRec(p->right, temp->data);
        }

        return p;
    }

    // wrapper to delete
    void deleteValue(int x) {
        root = deleteNodeRec(root, x);
    }

    // inorder traversal (sorted)
    void inorder(Node* p) {
        if (p == NULL) return;

        inorder(p->left);
        cout << p->data << " ";
        inorder(p->right);
    }

    void printInorder() {
        inorder(root);
        cout << endl;
    }

};





int main() {
    return 0;
}
