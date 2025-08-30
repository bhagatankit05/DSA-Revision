#include <bits/stdc++.h>
using namespace std;

int searchInsert(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; 
        } else if (arr[mid] < target) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }
    return left;
}

int main() {
    int arr[] = {1, 3, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target;
    cout << "Enter target: ";
    cin >> target;

    cout << "Insert position: " << searchInsert(arr, n, target) << endl;

    return 0;
}
