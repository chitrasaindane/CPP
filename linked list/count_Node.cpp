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
   
    }
    else{
      temp=head;
     while (temp->next != nullptr) {
            temp = temp->next;   
        }
        temp->next = newNode;
    }
}

int count(){
    int c=0;
    Node* p = head;
    while(p != nullptr){
        c++ ;
        p=p->next;
    }
    return c;
}



int main() {
    
    createNode(10); 
    createNode(20); 
    createNode(30); 
    createNode(40);

     

    cout << "Count of Nodes in Linked List: ";
    cout<<count();



    
    Node* t;
    while (head != nullptr) {
        t = head;
        head = head->next;
        delete t;
    }

    return 0;
}