#include <bits/stdc++.h>
using namespace std;

int findOddOccur(vector<int> &arr)
{
    int res = 0;
    for (int num : arr)
    {
        res ^= num; // XOR all numbers
    }
    return res;
}

int main()
{
    int n;
    cin >> n; 
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << findOddOccur(arr) << "\n";
    return 0;
}
