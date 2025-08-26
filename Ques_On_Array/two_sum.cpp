//imp questions for an interview.
#include <iostream>
using namespace std;

void twoSum(int nums[], int n, int target) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                cout << "Indices: " << i << " and " << j << endl;
                return;
            }
        }
    }
}


int main() {
    int nums[] = {2, 7, 11, 15};
    int n = sizeof(nums) / sizeof(nums[0]);
    int target = 9;

    twoSum(nums, n, target);
    return 0;
}
