#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

bool isEmpty(Node* top) {
    return top == nullptr;
}

void push(Node*& top, int value) {
    Node* newNode = createNode(value);
    newNode->next = top;
    top = newNode;
}

void pop(Node*& top) {
    if (isEmpty(top)) {
        cout << "Stack is empty!" << endl;
        return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
}

int topElement(Node* top) {
    if (isEmpty(top)) {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    return top->data;
}

int positionOfElement(Node* top, int value) {
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

void display(Node* top) {
    if (isEmpty(top)) {
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

int main() {
      Node* top = nullptr;

    push(top, 10);
    push(top, 20);
    push(top, 30);
    push(top, 40);

    display(top);

    cout << "Top element: " << topElement(top) << endl;

    int pos = positionOfElement(top, 20);
    if (pos != -1) {
        cout << "Position of 20: " << pos << endl;
    } else {
        cout << "Element not found!" << endl;
    }

    pop(top);
    cout << "Top element after pop: " << topElement(top) << endl;

    display(top);

    if (isEmpty(top)) {
        cout << "Stack is empty!" << endl;
    } else {
        cout << "Stack is not empty!" << endl;
    }

    return 0;
}