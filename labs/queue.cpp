#include <iostream>
#include <string>
using namespace std;



class Queue {
    string arr[size];
    int front, rear, count;

public:
    Queue(int size) {
        front = 0;
        rear  = 0;
        count = 0;
    }

    bool enqueue(string name) {
        if (count == size) {
            cout << "Queue is full!\n";
            return false;
        }
        arr[rear] = name;
        rear = (rear + 1) % size;
        count++;
        return true;
    }

    string dequeue() {
        if (isEmpty()) return "No customers waiting!";
        string served = arr[front];
        front = (front + 1) % size;
        count--;
        return served;
    }

    bool isEmpty() { return count == 0; }
    void showQueue() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Current queue: ";
        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % size] << " ";
        }
        cout << endl;
    }
};



int main() {
    Queue serviceQueue;
    int choice;
    string name;

    cout << "Customer Service Queue System\n";
    cout << "--------------------------------\n";

    do {
        cout << "\n1. Add customer\n2. Serve customer\n3. Show waiting list\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter customer name: ";
                cin >> name;
                serviceQueue.enqueue(name);
                break;

            case 2:
                cout << "Serving: " << serviceQueue.dequeue() << endl;
                break;

            case 3:
                serviceQueue.showQueue();
                break;

            case 0:
                cout << "Closing customer service...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    } while (choice != 0);

    return 0;
}


