// Insert the node at last position

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = nullptr;

Node createNode(int data)
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
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display()
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << "->";
        current = current->next;
    }
    cout << "NULL" << endl;
}
void insert_at_pos(int data, int pos)
{

    Node *newNode = new Node();
    newNode->data = data;
    

    Node *t = head;
    int i = 1; 
    while (i<pos-1)
    {
        t=t->next;
        i++;
    }

    newNode->next = t->next;
    t->next = newNode;
}

int main()
{
    createNode(10);
    createNode(20);
    createNode(30);
    createNode(40);

    insert_at_pos(100 , 3);
    insert_at_pos(200,4);

    cout << "Linked list elements: ";
    display();
    Node *temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}