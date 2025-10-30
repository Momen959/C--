#include <iostream>
#include <string>
using namespace std;

class Stack {
    string arr[10];
    int top;

public:
    Stack() { top = -1; }

    bool push(string page) {
        if (top >= 9) return false;
        arr[++top] = page;
        return true;
    }

    string pop() {
        if (isEmpty()) return "No history!";
        return arr[top--];
    }

    string peek() {
        if (isEmpty()) return "No current page";
        return arr[top];
    }

    bool isEmpty() { return top < 0; }
};


class Queue {
    string arr[10];
    int front, rear, count;

public:
    Queue() {
        front = 0;
        rear = 0;
        count = 0;
    }

    bool enqueue(string name) {
        if (count == 10) {
            cout << "Queue is full!\n";
            return false;
        }
        arr[rear] = name;
        rear = (rear + 1) % 10;
        count++;
        return true;
    }

    string dequeue() {
        if (isEmpty()) return "No customers waiting!";
        string served = arr[front];
        front = (front + 1) % 10;
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
            cout << arr[(front + i) % 10] << " ";
        }
        cout << endl;
    }
};

// int main() {
//     Stack history;
//     int choice;
//     string page;

//     cout << "Browser History System\n";
//     cout << "------------------------\n";

//     do {
//         cout << "\n1. Visit new page\n2. Go back\n3. Show current page\n0. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1:
//                 cout << "Enter page name: ";
//                 cin >> page;
//                 history.push(page);
//                 cout << "Visited: " << page << endl;
//                 break;

//             case 2:
//                 cout << "Going back from: " << history.pop() << endl;
//                 cout << "Now at: " << history.peek() << endl;
//                 break;

//             case 3:
//                 cout << "Current page: " << history.peek() << endl;
//                 break;

//             case 0:
//                 cout << "Exiting browser history...\n";
//                 break;

//             default:
//                 cout << "Invalid choice! Try again.\n";
//         }
//     cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
//     } while (choice != 0);

//     return 0;
// }


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


