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

// Function to delete the root element from the heap
void deleteHeap(int a[], int &n) {
    int x = a[1]; // Root element to delete
    a[1] = a[n];  // Replace root with last element
    n--; // Reduce heap size

    int i = 1, j = 2 * i;
    while (j <= n) {
        if (j < n && a[j] < a[j + 1]) {
            j++; // Move to the larger child
        }
        if (a[i] < a[j]) {
            swap(a[i], a[j]); // Swap if parent is smaller
            i = j;
            j = 2 * i;
        } else {
            break;
        }
    }
}

// Heap Sort Function
void heapSort(int a[], int n) {
    for (int i = n; i > 1; i--) {
        swap(a[1], a[i]); // Move max element to end
        int temp_n = i - 1;
        deleteHeap(a, temp_n); // Rebuild the heap
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
    
    heapSort(a, n);
    cout << "Sorted array using Heap Sort: ";
    display(a, n);
    
    return 0;
}
