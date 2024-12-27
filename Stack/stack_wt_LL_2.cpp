#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;  
    }
};

class Stack {
private:
    Node* top;  
public:
    Stack() {
        top = nullptr;  
    }

    bool isEmpty() {
        return top == nullptr;
    }

    bool isFull() {
        return false;  
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int topElement() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;  
        }
        return top->data;
    }

    int positionOfElement(int value) {
        int position = 1;
        Node* temp = top;
        while (temp != nullptr) {
            if (temp->data == value) {
                return position;
            }
            temp = temp->next;
            position++;
        }
        return -1;  
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);

    stack.display();

    cout << "Top element: " << stack.topElement() << endl;

    int pos = stack.positionOfElement(20);
    if (pos != -1) {
        cout << "Position of 20: " << pos << endl;
    } else {
        cout << "Element not found!" << endl;
    }

    stack.pop();
    cout << "Top element after pop: " << stack.topElement() << endl;

    stack.display();

    if (stack.isEmpty()) {
        cout << "Stack is empty!" << endl;
    } else {
        cout << "Stack is not empty!" << endl;
    }

    return 0;
}
