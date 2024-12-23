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

int Max_ele()
{
    Node *p = head;
    int max = INT8_MIN;
    while (p != nullptr)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

int main()
{

    createNode(10);
    createNode(20);
    createNode(30);
    createNode(40);

    cout << "MAX Element : ";
    cout << Max_ele();

    Node *t;
    while (head != nullptr)
    {
        t = head;
        head = head->next;
        delete t;
    }

    return 0;
}