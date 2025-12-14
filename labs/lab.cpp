#include <iostream>
using namespace std;



class DoublyLinkedList{
    struct Node{
        Node* prev;
        int data;
        Node* next;

        Node(int value){
            this->prev = nullptr;
            this->data = value;
            this->next = nullptr;
        }
    };

    Node* head;

    DoublyLinkedList(){
        head = nullptr;
    }

    void addAtEnd(int value){
        Node* newNode = new Node(value);
        Node* current = head;
        while(current->next !=nullptr){
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }

    void deleteAtEnd(){
        Node* current = head;
        while(current->next->next != nullptr)
        {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = nullptr;
        delete temp;
    }
};


class CircularLinkedList{
    struct Node{
        int data;
        Node* next;
        Node(int value){
            this->data = value;
            this->next = nullptr;
        }
    };

    Node* last;

    CircularLinkedList(){
        last = last->next;
    }

    void insertAtStart(int value){
        if(last == nullptr){
            last = new Node(value);
            last->next = last;
            return;
        }
        Node* newNode = new Node(value);
        newNode->next = last->next;
        last->next = newNode;
        
    }
};