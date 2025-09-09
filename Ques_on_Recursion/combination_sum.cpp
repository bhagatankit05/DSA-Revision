#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void findCombinations(int index, int target, vector<int>& candidates,
                          vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

       
        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] <= target) {
                
                current.push_back(candidates[i]);

                findCombinations(i, target - candidates[i], candidates, current, result);
                current.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        findCombinations(0, target, candidates, current, result);
        return result;
    }
};

int main() {
    Solution s;

    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> ans = s.combinationSum(candidates, target);

    cout << "Combinations that sum to " << target << " are:\n";
    for (auto &comb : ans) {
        cout << "[ ";
        for (int num : comb)
            cout << num << " ";
        cout << "]\n";
    }

    return 0;
}
