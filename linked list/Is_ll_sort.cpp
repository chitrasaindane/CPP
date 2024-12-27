#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

Node *createLinkedList(int arr[], int size)
{
    if (size == 0)
        return nullptr;

    Node *head = createNode(arr[0]);
    Node *current = head;

    for (int i = 1; i < size; i++)
    {
        current->next = createNode(arr[i]);
        current = current->next;
    }
    return head;
}

bool is_LL_Sort(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return true;
    }

    Node *curr = head;
    while (curr->next != nullptr)
    {
        if (curr->data > curr->next->data)
        {
            return false;
        }

        curr = curr->next;
    }

    return true;
}

void displayLinkedList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main()
{
    int arr[] = {10, 20, 30, 40};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node *head = createLinkedList(arr, size);

    cout << "Initial linked list: "<<endl;
    displayLinkedList(head);
    
    cout<<"Is linked List Sorted? ";
    cout<< is_LL_Sort(head)<<endl;

    return 0;
}
