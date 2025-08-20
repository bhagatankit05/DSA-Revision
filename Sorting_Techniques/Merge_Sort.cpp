#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high) {
    int n = high - low + 1;   // total elements
    int temp[n];            
    int left = low;           
    int right = mid + 1;      
    int k = 0;             

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp[k++] = arr[left++];
        } else {
            temp[k++] = arr[right++];
        }
    }

    // Copy remaining elements
    while (left <= mid) {
        temp[k++] = arr[left++];
    }

    // Copy remaining elements
    while (right <= high) {
        temp[k++] = arr[right++];
    }

    // Copy back temp array into original array
    for (int i = 0; i < n; i++) {
        arr[low + i] = temp[i];
    }
}

void mergeSort(int arr[], int low, int high) {
    if (low >= high) return;  
    
    int mid = (low + high) / 2;

    // Sort left half
    mergeSort(arr, low, mid);

    // Sort right half
    mergeSort(arr, mid + 1, high);

    // Merge both halves
    merge(arr, low, mid, high);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
