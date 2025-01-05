#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node* front; 
    Node* rear;  

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Add an element to the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) { 
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " enqueued.\n";
    }

    // Remove an element from the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue.\n";
            return -1;
        }

        Node* temp = front;
        int value = temp->data;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        return value;
    }

    // Display the elements of the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << "Queue elements are: ";
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    cout << "Dequeued: " << q.dequeue() << endl;
    q.display();

    q.enqueue(40);
    q.enqueue(50);
    q.display();

    return 0;
}
