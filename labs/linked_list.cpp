#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
class Linkedlist {
public:
    Node *head;
    Linkedlist(){
        head = NULL;
    }
    void push(int x){
        Node* newNode;
        newNode->data = x; 
        if(head == NULL){
           head = newNode;
           newNode->next = NULL;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }
    void append(int x){
        
    }
    void presert(int x, int loc){

    }
    void insert(int x, int loc){

    }
};
int main(){
    return 0;
}