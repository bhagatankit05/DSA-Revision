#include <iostream>
using namespace std;

int findMaxConsecutiveOnes(int nums[], int n) {
    int count = 0;       
    int maxCount = 0; 

    for (int i = 0; i < n; i++) {
        if (nums[i] == 1) {
            count++;
            if (count > maxCount)
                maxCount = count;
        } else {
            count = 0;
        }
    }

    return maxCount;
}

int main() {
    int nums[] = {1, 1, 0, 1, 1, 1,1};   
    int n = sizeof(nums) / sizeof(nums[0]);
    
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    cout << "Max consecutive ones = " << findMaxConsecutiveOnes(nums, n) << endl;

    return 0;
}
