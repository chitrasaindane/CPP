
#include <iostream>
using namespace std;

// Function to insert an element into the heap
void insert(int a[], int n) {
    int temp, i = n;
    temp = a[n];
    while (i > 1 && temp > a[i / 2]) { 
        a[i] = a[i / 2];
        i = i / 2;
    }
    a[i] = temp;
}

// Function to create a heap from an array
void create(int a[], int n) {
    for (int i = 2; i <= n; i++) {
        insert(a, i);
    }
}

// Function to display the heap
void display(int a[], int n) {
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[] = {0, 10, 20, 30, 25, 5, 40, 35}; // index 0 is unused
    int n = 7; // Number of elements
    
    create(a, n);
    cout << "Heap after creation: ";
    display(a, n);
    
    return 0;
}
