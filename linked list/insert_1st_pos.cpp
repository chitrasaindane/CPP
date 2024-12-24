//Insert the node at first position

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next ;
};

Node* head = nullptr;


Node createNode(int data){
    Node* newNode = new Node();
    newNode-> data = data;
    newNode-> next =nullptr;

    if(head == nullptr){
        head = newNode;
    }
    else{
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp-> next = newNode;
    }
}

void display(){
    Node* current = head;
    while(current != nullptr){
        cout<< current->data<<"->";
        current=current->next;
    }
    cout<<"NULL"<<endl;
}

void insert_at_first_pos(int data){

Node* newNode = new Node();
newNode->data = data;
newNode->next = head;
head= newNode;
}

int main(){
    createNode(10); 
    createNode(20); 
    createNode(30); 
    createNode(40);

    insert_at_first_pos(100);
    insert_at_first_pos(200);


    cout << "Linked list elements: ";
    display();

    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}