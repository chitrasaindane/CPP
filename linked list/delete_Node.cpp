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

Node* createLinkedList(int arr[], int size) {
    if (size == 0) return nullptr;

    Node* head = createNode(arr[0]);
    Node* current = head;

    for (int i = 1; i < size; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }
    return head;
}

Node* deleteNode(Node* head, int position) {
    if (head == nullptr) {
        cout << "The list is empty.\n";
        return nullptr;
    }

    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* current = head;
    Node* previous = nullptr;
    int count = 1;

    while (current != nullptr && count < position) {
        previous = current;
        current = current->next;
        count++;
    }

    if (current == nullptr) {
        cout << "Position out of range.\n";
        return head;
    }

    if (current->next == nullptr) {
        previous->next = nullptr;
        delete current;
        return head;
    }

    previous->next = current->next;
    delete current;

    return head;
}

void displayLinkedList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "nullptr\n";
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node* head = createLinkedList(arr, size);

    cout << "Initial linked list: ";
    displayLinkedList(head);

    head = deleteNode(head, 1);
    cout << "After deleting the first node: ";
    displayLinkedList(head);

    head = deleteNode(head, size - 1);
    cout << "After deleting the last node: ";
    displayLinkedList(head);

    head = deleteNode(head, 2);
    cout << "After deleting node at position 2: ";
    displayLinkedList(head);

    return 0;
}
