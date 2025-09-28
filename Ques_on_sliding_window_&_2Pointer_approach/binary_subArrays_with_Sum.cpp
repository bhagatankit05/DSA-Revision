#include <bits/stdc++.h>
using namespace std;

int numSubarraysWithSum(vector<int>& arr, int S) {
    int n = arr.size();
    int left = 0;
    int sum = 0;
    int count = 0;

    for (int right = 0; right < n; right++) {
        sum += arr[right];

        while (sum > S && left <= right) {
            sum -= arr[left];
            left++;
        }

        if (sum  == S) {
            int temp = left;
            while (temp <= right && arr[temp] == 0) {
                count++;
                temp++;
            }
            count++;
        }
    }

    return count;
}

int main() {
    vector<int> arr = {1, 0, 1, 0, 1};
    int S = 2;

    cout << "Number of subarrays with sum " << S << " = " 
         << numSubarraysWithSum(arr, S) << endl;

    return 0;
}
