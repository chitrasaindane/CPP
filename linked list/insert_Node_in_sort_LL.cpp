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

Node* insertSorted(Node* head, int data) {
    Node* newNode = createNode(data);

    if (head == nullptr || head->data >= data) {
        newNode->next = head;
        return newNode;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data < data) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;

    return head;
}

void displayLinkedList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    int arr[] = {10, 20, 30, 40};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node* head = createLinkedList(arr, size);

    cout << "Initial linked list: ";
    displayLinkedList(head);

    head = insertSorted(head, 25);
    cout << "After inserting 25: ";
    displayLinkedList(head);

    head = insertSorted(head, 5);
    cout << "After inserting 5: ";
    displayLinkedList(head);

    head = insertSorted(head, 50);
    cout << "After inserting 50: ";
    displayLinkedList(head);

    return 0;
}
