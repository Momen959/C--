#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next = NULL;
};
class Linkedlist {
public:
    Node* head;
    Linkedlist(){
        head = NULL;
    }
    void push(int x){
        Node* newNode;
        newNode->data = x; 
        if(head == NULL){
           head = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }
    void append(int x){
        Node* newNode;
        newNode->data = x;
        Node* current = head;
        while (current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
    void presert(int x, int loc){

    }
    void insert(int x, int loc){

    }
};
int main(){
    return 0;
}