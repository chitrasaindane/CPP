#include <iostream>
using namespace std;

// Function to heapify a subtree rooted at index i
void heapify(int a[], int n, int i) {
    int largest = i;       // Assume root is largest
    int left = 2 * i;      // Left child index
    int right = 2 * i + 1; // Right child index

    // Compare with left child
    if (left <= n && a[left] > a[largest])
        largest = left;

    // Compare with right child
    if (right <= n && a[right] > a[largest])
        largest = right;

    // If largest is not root, swap and heapify the affected subtree
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest); // Recursively heapify the affected subtree
    }
}

// Function to build a max heap using heapify
void buildHeap(int a[], int n) {
    // Start from the last non-leaf node (n/2) and move up
    for (int i = n / 2; i >= 1; i--) {
        heapify(a, n, i);
    }
}

// Function to display the heap
void display(int a[], int n) {
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    int a[] = {0, 10, 20, 30, 25, 5, 40, 35}; // Index 0 is unused
    int n = 7; // Number of elements

    buildHeap(a, n); 

    cout << "Heap after creation: ";
    display(a, n);

    return 0;
}
