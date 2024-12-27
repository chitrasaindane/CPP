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

void Remove_duplicates(Node *head)
{
    Node *curr = head;

    while (curr->next != nullptr)
    {
        if (curr->data == curr->next->data)
        {

            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else
        {
            curr = curr->next;
        }
    }
}

void displayLinkedList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "nullptr\n";
}

int main()
{
    int arr[] = {10, 20, 30, 30,40, 50, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node *head = createLinkedList(arr, size);

    cout << "Initial linked list: ";
    displayLinkedList(head);
    cout << endl;
    cout << "Remove Duplicate:";
    Remove_duplicates(head);
    displayLinkedList(head);

    return 0;
}
