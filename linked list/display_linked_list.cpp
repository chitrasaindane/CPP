#include <iostream>
using namespace std;

struct Node {
    int data;         
    Node* next;       
};

Node* head = nullptr ;
Node* temp;

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    

    if(head == nullptr)
    {   head= newNode;
        temp = head;
       
    }
    else{
     temp=head;
     while (temp->next != nullptr) {
            temp = temp->next;   
        }
        temp->next = newNode;
    }
}


void displayLinkedList() {
    Node* current = head; 
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next; 
    }
    cout << "NULL" << endl; 
}

int main() {
    
    createNode(10); 
    createNode(20); 
    createNode(30); 
    createNode(40);

   
    cout << "Linked list elements: ";
    displayLinkedList();

    
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
