#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    unordered_set<int> used;
    vector<vector<int>> permute(vector<int>& nums) {
        backtracking(nums);
        return result;
    }

    void backtracking(const vector<int>& nums)
    {
        if (path.size() == nums.size())
        {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
	        if (used.find(nums[i]) != used.end())
                continue;
            path.push_back(nums[i]);
            used.insert(nums[i]);
            backtracking(nums);
            path.pop_back();
            used.erase(nums[i]);
        }
    }
};