#include <iostream>
// #define size 6;

class stack {
    // int arr[size];
    int top;
    stack(int size){
        top = -1;
    }
    int push(int value){
        if(isFull()){
            return -1;
        }else{
            arr[++top] = value;
        }
    }
    int pop(){
        if(isEmpty()){
            return -1;
        }else{
            return arr[top--];
        }
    }
    bool isEmpty(){
        return top < 0;
    }
    bool isFull(){
        return top  == size-1;
    }
}

int main{
    int size;
    cin >> size;
    stack(size);
}