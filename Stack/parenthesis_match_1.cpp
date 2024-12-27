#include <iostream>
using namespace std;

struct Stack {
    char* arr;
    int top;
    int capacity;

    Stack(int size) {
        capacity = size;
        arr = new char[capacity];
        top = -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(char c) {
        if (isFull()) {
            cout << "Stack overflow!" << endl;
            return;
        }
        arr[++top] = c;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
            return '\0'; // Return null character when stack is empty
        }
        return arr[top--];
    }

    ~Stack() {
        delete[] arr;
    }
};

bool isBalanced(const string& expression) {
    Stack s(expression.length());  

    for (char c : expression) {
        if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            if (s.isEmpty()) {
                return false; 
            }
            s.pop();
        }
    }

    return s.isEmpty();
}

int main() {
    string expression;

    cout << "Enter an expression: ";
    cin >> expression;

    if (isBalanced(expression)) {
        cout << "The parentheses are balanced." << endl;
    } else {
        cout << "The parentheses are not balanced." << endl;
    }

    return 0;
}
