#include <iostream>
using namespace std;

class Linkelist{

    struct Node{
        int Data;
        Node *next = NULL;
    };

    Node *head;
    

    public:
    Linkelist(){
        head = NULL;
    }


    void addFront(int x){
        Node *newnode = new Node();
        newnode -> Data = x;

        if (head == NULL){
            head = newnode;
            newnode -> next = NULL;
        }else{
            newnode -> next = head;
            head = newnode;
        }
    }


    void addRear(int x){
        Node *newnode = new Node();
        newnode -> Data = x;

        if (head == NULL){
            head = newnode;
            newnode -> next = NULL;
            return;
        }

        Node *end = head;
        while (end -> next != NULL){
            end = end -> next;
        }

        end -> next = newnode;
        newnode -> next = NULL;
    }


    void insertbetween(int x, int index){
        Node *p = head;
        Node *newnode = new Node();
        newnode -> Data = x;

        int c = 1;
        while (p -> next != NULL && c != index){
           p = p -> next;
           c++;
        }

        newnode -> next = p -> next;
        p -> next = newnode;
    }


    // insert before a node that has a specific value
    void insertbeforeVal(int x, int val){
        Node *p = head;
        Node *newnode = new Node();
        newnode -> Data = x;

        if (head == NULL) return;

        // value is at head
        if (head -> Data == val){
            newnode -> next = head;
            head = newnode;
            return;
        }

        while (p -> next != NULL && p -> next -> Data != val){
            p = p -> next;
        }

        if (p -> next == NULL) return;

        newnode -> next = p -> next;
        p -> next = newnode;
    }


    // insert after a node that has a specific value
    void insertafterVal(int x, int val){
        Node *p = head;
        Node *newnode = new Node();
        newnode -> Data = x;

        while (p != NULL && p -> Data != val){
            p = p -> next;
        }

        if (p == NULL) return;

        newnode -> next = p -> next;
        p -> next = newnode;
    }


    // delete the node that has the given value
    void deleteValue(int val){
        if (head == NULL) {
            return;
        }
        if (head -> Data == val){
            Node *temp = head;
            head = head -> next;
            delete temp;
            return;
        }

        Node *p = head;
        while (p -> next != NULL && p -> next -> Data != val){
            p = p -> next;
        }

        if (p -> next == NULL) return;

        Node *temp = p -> next;
        p -> next = temp -> next;
        delete temp;
    }

};


class DoublyLinkedList {

    struct Node {
        int data;
        Node* next;
        Node* prev;
    };

    Node* head;
    Node* tail;

public:

    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }


    void addFront(int x) {
        Node* newnode = new Node;
        newnode->data = x;
        newnode->prev = NULL;
        newnode->next = head;

        if (head != NULL)
            head->prev = newnode;
        else 
            tail = newnode;

        head = newnode;
    }

    
    void addRear(int x) {
        Node* newnode = new Node;
        newnode->data = x;
        newnode->next = NULL;
        newnode->prev = tail;

        if (tail != NULL)
            tail->next = newnode;
        else
            head = newnode;

        tail = newnode;
    }


    // insert at a specific index number
    void insertAt(int x, int index) {
        if (index == 0) {
            addFront(x);
            return;
        }

        Node* p = head;
        int c = 0;

        while (p != NULL && c < index - 1) {
            p = p->next;
            c++;
        }

        if (p == NULL) {
            return;
        }

        Node* newnode = new Node;
        newnode->data = x;
        newnode->next = p->next;
        newnode->prev = p;

        if (p->next != NULL)
            p->next->prev = newnode;
        else
            tail = newnode;

        p->next = newnode;
    }


    // delete the first node that has this value
    void deleteValue(int val) {
        Node* p = head;

        while (p != NULL && p->data != val)
            p = p->next;

        if (p == NULL) return;

        if (p->prev != NULL)
            p->prev->next = p->next;
        else
            head = p->next;

        if (p->next != NULL)
            p->next->prev = p->prev;
        else
            tail = p->prev;

        delete p;
    }

};



class CircularLinkedList {

    struct Node {
        int data;
        Node* next;
    };

    Node* head;

public:

    CircularLinkedList() {
        head = NULL;
    }

    void addFront(int x) {
        Node* newnode = new Node;
        newnode->data = x;

        if (head == NULL) {
            head = newnode;
            newnode->next = head;
            return;
        }

        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }

        newnode->next = head;
        last->next = newnode;
        head = newnode;
    }

    void addRear(int x) {
        Node* newnode = new Node;
        newnode->data = x;

        if (head == NULL) {
            head = newnode;
            newnode->next = head;
            return;
        }

        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }

        last->next = newnode;
        newnode->next = head;
    }

    // delete a node with specific value
    void deleteValue(int val) {
        if (head == NULL) return;

        
        if (head->data == val) {
            Node* last = head;
            while (last->next != head)
                last = last->next;

            if (head == last) { 
                delete head;
                head = NULL;
                return;
            }

            last->next = head->next;
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* p = head;
        while (p->next != head && p->next->data != val) {
            p = p->next;
        }

        if (p->next == head) return;

        Node* temp = p->next;
        p->next = temp->next;
        delete temp;
    }


    // merge two circular lists
    void mergeWith(CircularLinkedList &other) {

        if (head == NULL) {
            head = other.head;
            return;
        }

        if (other.head == NULL) return;

        Node* last1 = head;
        while (last1->next != head) {
            last1 = last1->next;
        }

        Node* last2 = other.head;
        while (last2->next != other.head) {
            last2 = last2->next;
        }

        last1->next = other.head;
        last2->next = head;
    }

};


int main(){
    return 0;
}