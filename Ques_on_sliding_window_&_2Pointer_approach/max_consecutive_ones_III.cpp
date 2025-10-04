#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int left = 0, zerosCount = 0, maxLen = 0;

    for (int right = 0; right < nums.size(); right++) {
        if (nums[right] == 0)
            zerosCount++;

        while (zerosCount > k) {
            if (nums[left] == 0)
                zerosCount--;
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    vector<int> nums = {1,1,0,0,1,1,1,0,1,1};
    int k = 2;
    cout << "Maximum consecutive ones after flipping " << k << " zeros = " 
         << longestOnes(nums, k) << endl;
    return 0;
}
