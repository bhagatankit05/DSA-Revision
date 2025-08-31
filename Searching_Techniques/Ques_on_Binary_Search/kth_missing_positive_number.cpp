//time complexity: O(log n)

#include <bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int missing = arr[mid] - (mid + 1);

        if (missing < k)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return left + k;
}

int main() {
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;

    // Print array 
    cout << "Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Print result
    cout << "The " << k << "th missing positive number is: "
         << findKthPositive(arr, k) << endl;

    return 0;
}


//alternate approach
/*  #include <bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int missingCount = 0, num = 1, i = 0;

    while (true) {
        if (i < arr.size() && arr[i] == num) {
            i++; // number is in array, skip it
        } else {
            missingCount++;
            if (missingCount == k) return num;
        }
        num++;
    }
}
    */
