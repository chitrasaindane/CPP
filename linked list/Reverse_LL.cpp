#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

Node* reverseLinkedList(Node* head) {
    Node* prev = nullptr;  
    Node* current = head;  
    Node* next = nullptr;  

    while (current != nullptr) {
        next = current->next; 
        current->next = prev; 
        prev = current;       
        current = next;       
    }

    return prev; 
}


void displayLinkedList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    cout << "Original linked list: ";
    displayLinkedList(head);

    head = reverseLinkedList(head);

    cout << "Reversed linked list: ";
    displayLinkedList(head);

    return 0;
}
