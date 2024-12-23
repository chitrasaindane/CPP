#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = nullptr;
Node *temp;
Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

Node* search_LL(int key)
{
    Node *p = head;
    int pos = 0;
    while (p != nullptr)
    {   
        pos++;
        if (p->data == key) {
            cout<< "key = "<< p->data << " position: "<< pos<<endl;; 
        }
        p=p->next;
    }
    
}

int main()
{

    createNode(10);
    createNode(20);
    createNode(30);
    createNode(40);

    cout << "Position of key in linked list : ";
    cout << search_LL(20);

    Node *t;
    while (head != nullptr)
    {
        t = head;
        head = head->next;
        delete t;
    }

    return 0;
}