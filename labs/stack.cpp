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




int main() {
    Stack history;
    int choice;
    string page;

    cout << "Browser History System\n";
    cout << "------------------------\n";

    do {
        cout << "\n1. Visit new page\n2. Go back\n3. Show current page\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter page name: ";
                cin >> page;
                history.push(page);
                cout << "Visited: " << page << endl;
                break;

            case 2:
                cout << "Going back from: " << history.pop() << endl;
                cout << "Now at: " << history.peek() << endl;
                break;

            case 3:
                cout << "Current page: " << history.peek() << endl;
                break;

            case 0:
                cout << "Exiting browser history...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    } while (choice != 0);

    return 0;
}