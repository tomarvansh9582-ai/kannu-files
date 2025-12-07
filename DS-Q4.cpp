#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Stack class (array-based implementation)
class Stack {
private:
    int top;
    int capacity;
    int* arr;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack overflow!" << endl;
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }
};

// Function to check if character is operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Evaluate postfix expression
int evaluatePostfix(string exp) {
    Stack st(exp.length());
    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];
        if (isdigit(c)) {
            st.push(c - '0'); // convert char to int
        } else if (isOperator(c)) {
            int val2 = st.pop();
            int val1 = st.pop();
            switch (c) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
                case '^': st.push(pow(val1, val2)); break;
            }
        }
    }
    return st.pop();
}

// Evaluate prefix expression
int evaluatePrefix(string exp) {
    Stack st(exp.length());
    for (int i = exp.length() - 1; i >= 0; i--) {
        char c = exp[i];
        if (isdigit(c)) {
            st.push(c - '0');
        } else if (isOperator(c)) {
            int val1 = st.pop();
            int val2 = st.pop();
            switch (c) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
                case '^': st.push(pow(val1, val2)); break;
            }
        }
    }
    return st.pop();
}

// Menu-driven program
int main() {
    int choice;
    string exp;

    do {
        cout << "\n--- Stack ADT Expression Evaluation ---\n";
        cout << "1. Evaluate Postfix Expression\n";
        cout << "2. Evaluate Prefix Expression\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter postfix expression (single-digit operands): ";
            cin >> exp;
            cout << "Result = " << evaluatePostfix(exp) << endl;
            break;
        case 2:
            cout << "Enter prefix expression (single-digit operands): ";
            cin >> exp;
            cout << "Result = " << evaluatePrefix(exp) << endl;
            break;
        case 0:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}

