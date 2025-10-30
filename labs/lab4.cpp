#include <iostream>
// #define size 6;

class queue{
    int arr[size];
    int front;
    int rear;
    queue(int size){
        front = -1;
        rear = 0;
    }
    bool isEmpty(){
        return rear == 0;
    }
    bool isFull(){
        return rear == size -1;
    }
    int enqueue(int value){
        if(isFull()){
            rear = 0;
            return -1;

        }else if(isEmpty()){
            arr[rear++] == value;
            front++
            retrun value;
        }
        arr[rear++] = value;
    }
    int dequeue(){
        if(isEmpty()){
            return -1;
        }
        return arr[front++];
    }

}

class stack {
    int arr[size];
    int top;
    stack(int size){
        top = -1;
    }
    int push(int value){
        if(isFull()){
            return -1;
        }
        arr[++top] = value;
        return value;
    }
    int pop(){
        if(isEmpty()){
            return -1;
        }
        return arr[top--];
    }
    bool isEmpty(){
        return top < 0;
    }
    bool isFull(){
        return top  == size-1;
    }
    int topValue(){
        if(isEmpty()){
            return -1;
        }
        return arr[top];
    }
    void printStack(){
        if(isEmpty()){
            cout << "no items";
        }
        for(int i = 0; i < size; i++){
            cout << arr[i] << " ";
            cout << endl;
        }
    }
}

int main{
    int size;
    cin >> size;
    stack(size);

}