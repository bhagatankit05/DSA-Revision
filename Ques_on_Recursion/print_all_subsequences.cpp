#include <iostream>
#include <vector>
using namespace std;

void backtrack(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
    
    result.push_back(current);

    for (int i = index; i < nums.size(); i++) {
        // Include nums[i]
        current.push_back(nums[i]);
        backtrack(i + 1, nums, current, result);
        // Exclude nums[i]
        current.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    backtrack(0, nums, current, result);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = subsets(nums);

    for (auto subset : ans) {
        cout << "[";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i < subset.size() - 1) cout << ",";
        }
        cout << "] ";
    }
    return 0;
}
