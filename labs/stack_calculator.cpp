#include <iostream>
#include <string>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class Stack{
private:
    Node* top;
public:
    Stack(){
        top = nullptr;
    }

    bool isEmpty(){
        return top == nullptr;
    }
    
    void push(int item){
        Node* newNode = new Node;
        newNode->data = item;
        newNode->next = top;
        top = newNode;
    }

    int pop(){
        if(isEmpty()){
            cout << "stack empty" << endl;
            return -1;
        }
        Node* popped = top;
        int item = popped->data;
        top = top->next;
        
        delete popped;
        return item;
    }

    int peek(){
        if(isEmpty()){
            cout << "stack empty" << endl;
            return -1;
        }

        return top->data;
    }

    
};

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

string infixToPostfix(string expression){
    Stack opStack;
    string postfix = "";

    for(int i = 0; i < expression.length(); i++){
        char c = expression[i];

        if(c == ' ') continue;

        if(isdigit(c)){
            postfix+=c;
            postfix+=" ";
        }

        else if (c == '(') {
            opStack.push(c);  // cast char to int if needed
        }

        // Step 4: Handle ')'
        else if (c == ')') {
            // TODO: pop until '('
            while (!opStack.isEmpty() && opStack.peek() != '(') {
                char op = opStack.pop();    // pop operator
                postfix += op;              
                postfix += ' ';             // add space
            }

            if (opStack.isEmpty()) {
                cout << "Error: Mismatched parentheses!" << endl;
                return "";
            }

            // pop the '(' from the stack but don't add to postfix
            opStack.pop();
                
            }

            // Step 5: Handle operators
        else if (isOperator(c)) {
            while (!opStack.isEmpty() && precedence(opStack.peek()) >= precedence(c)) {
                postfix += opStack.pop();
                postfix += ' ';
            }
            opStack.push(c);

        }

        else {
                cout << "Invalid character: " << c << endl;
                return "";
        }
    }

    while (!opStack.isEmpty()) {
        char op = opStack.pop();
        if (op == '(' || op == ')') {
            cout << "Error: Mismatched parentheses!" << endl;
            return "";
        }
        postfix += op;
        postfix += ' ';
    }


    return postfix;
}



int evaluatePostfix(string expression) {
    Stack st;

    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];

        if (isdigit(c)) {
            st.push(c - '0');
        }
        else if (isOperator(c)) {
            int b = st.pop();
            int a = st.pop();

            int result;

            if (c == '+') result = a + b;
            else if (c == '-') result = a - b;
            else if (c == '*') result = a * b;
            else if (c == '/') {
                
                result = a / b;
            }

            st.push(result);
        }
        
    }

    return st.pop();
}


int main() {
    string infix;

    cout << "Enter an infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);

    if (postfix != "") { 
        cout << "Postfix expression: " << postfix << endl;
        int result = evaluatePostfix(postfix);
        cout << "Result: " << result << endl;
    }

    return 0;
}
