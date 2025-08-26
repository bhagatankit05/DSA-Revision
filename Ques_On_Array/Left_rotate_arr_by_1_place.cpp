#include <iostream>
using namespace std;

void leftRotateByOne(int arr[], int n) {
    int first = arr[0]; 
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1]; 
    }
    arr[n - 1] = first; 
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    leftRotateByOne(arr, n);

    cout << "After left rotation by one: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
