#include <iostream>
using namespace std;


int partition(int a[], int low, int high) {
    int pivot = a[high];  
    int i = low - 1;      

    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;  
            swap(a[i], a[j]);  
        }
    }

    swap(a[i + 1], a[high]);
    
    return i + 1;  
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        
        int pivotIndex = partition(a, low, high);

        quickSort(a, low, pivotIndex - 1);  
        quickSort(a, pivotIndex + 1, high); 
    }
}

int main() {
    int a[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(a) / sizeof(a[0]);

    quickSort(a, 0, n - 1);  

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
