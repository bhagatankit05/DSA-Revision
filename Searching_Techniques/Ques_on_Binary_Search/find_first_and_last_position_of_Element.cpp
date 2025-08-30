#include <bits/stdc++.h>
using namespace std;

int findFirst(int arr[], int n, int target) {
    int left = 0, right = n - 1, ans = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            ans = mid;
            right = mid - 1; 
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int findLast(int arr[], int n, int target) {
    int left = 0, right = n - 1, ans = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            ans = mid;
            left = mid + 1; 
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int main() {
    int arr[] = {5, 7, 7, 8, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Enter target: ";
    cin >> target;

    int first = findFirst(arr, n, target);
    int last = findLast(arr, n, target);

    cout << "[" << first << ", " << last << "]" << endl;
    return 0;
}
