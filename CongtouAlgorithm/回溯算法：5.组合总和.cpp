#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracing(candidates, target, 0, 0);
        return result;
    }

    void backtracing(const vector<int> &candidates, int target, int sum, int startIdx)
    {
        if (sum > target) return;
        if (sum == target)
        {
            result.push_back(path);
            return;
        }
        for (int i = startIdx; i < candidates.size(); i++)
        {
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracing(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }
};