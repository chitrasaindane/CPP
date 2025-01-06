#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    int i, j, k; 
    // i for the current position
    // j for iteration
    // k for tracking the smallest element's index

    for (i = 0; i < n - 1; i++) {
        k = i; 
    
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[k]) {
                k = j; 
            }
        }
        
        if (k != i) {
            swap(arr[i], arr[k]);
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {5, 3, 8, 6, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    selectionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
