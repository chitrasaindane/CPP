#include <iostream>
using namespace std;

class Queue {
    int *q;  
    int front, rear, size;

public:
    Queue(int size) {
        this->size = size;
        q = new int[size];  
        front = -1;
        rear = -1;
    }

    // Enqueue operation
    void enqueue(int value) {
        if (rear == size - 1) {
            cout << "Queue is full!" << endl;
        } 
        else {
            if (front == -1) front = 0;
            rear++;
            q[rear] = value;  
            cout << value << " added to the queue." << endl;
        }
    }

    // Dequeue operation
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << q[front] << " removed from the queue." << endl;  // Using q instead of arr
            front++;
        }
    }

    // Display the queue
    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++) {
                cout << q[i] << " ";  
            }
            cout << endl;
        }
    }

    ~Queue() {
        delete[] q;  
    }
};

int main() {
    int size, value, choice;

    cout << "Enter the size of the queue: ";
    cin >> size;

    Queue q(size);

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}
