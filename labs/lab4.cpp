#include <iostream>
// #define size 6;

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