#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> used;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        for (int i = 0; i < candidates.size(); i++)
        {
            used.push_back(false);
        }
        backtracking(candidates, target, 0, 0);
        return result;
    }

    void backtracking(const vector<int>& candidates, int target, int sum, int startIdx)
    {
        if (sum > target) return;
        if (sum == target)
        {
            result.push_back(path);
            return;
        }
        for (int i = startIdx; i < candidates.size(); i++)
        {
            //剪枝：当前元素与前一个元素相同，且前一个元素没有使用过
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false)
                continue;
            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates, target, sum, i + 1);
            sum -= candidates[i];
            path.pop_back();
            used[i] = false;
        }
    }
};