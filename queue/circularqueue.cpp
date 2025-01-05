#include <iostream>
using namespace std;

class CircularQueue {
private:
    int front, rear;
    int size;
    int* q; 

public:
    CircularQueue(int s) {
        size = s;
        front = -1;
        rear = -1;
        q = new int[s];
    }

    ~CircularQueue() {
        delete[] q;
    }

    bool isFull() {
        return (front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1));
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full!\n";
            return;
        }

        if (front == -1) { 
            front = rear = 0;
        } else if (rear == size - 1 && front != 0) { 
            rear = 0;
        } else { 
            rear++;
        }
        q[rear] = value; 
        cout << value << " enqueued.\n";
    }

    // Remove an element from the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return -1;
        }

        int value = q[front]; 
        q[front] = -1; 

        if (front == rear) { 
            front = rear = -1;
        } else if (front == size - 1) { 
            front = 0;
        } else { 
            front++;
        }

        return value;
    }

    // Display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << "Queue elements are: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                cout << q[i] << " "; 
            }
        } else {
            for (int i = front; i < size; i++) {
                cout << q[i] << " "; 
            }
            for (int i = 0; i <= rear; i++) {
                cout << q[i] << " "; 
            }
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the Circular Queue: ";
    cin >> size;

    CircularQueue q(size);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();

    cout << "Dequeued: " << q.dequeue() << endl;
    q.display();

    q.enqueue(50);
    q.display();

    return 0;
}
