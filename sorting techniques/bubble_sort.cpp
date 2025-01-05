#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {

        int flag = 0; 

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                
                swap(arr[j], arr[j + 1]);

                flag = 1; 
            }
        }
        
        if (flag == 0)
            break;
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Unsorted Array: ";
    display(arr, n);

    bubbleSort(arr, n);

    cout << "Sorted Array: ";
    display(arr, n);

    return 0;
}
