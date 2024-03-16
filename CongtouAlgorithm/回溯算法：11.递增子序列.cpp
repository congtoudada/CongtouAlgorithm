#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return result;
    }

    void backtracking(const vector<int>& nums, int startIdx)
    {
        //不满足个数要求不计入
	    if (path.size() > 1)
	    {
            result.push_back(path);
	    }
        unordered_set<int> used;
        for (int i = startIdx; i < nums.size(); i++)
        {
            //不满足递增或树层重复
	        if (!path.empty() && nums[i] < path.back() || 
                used.find(nums[i]) != used.end())
                continue;

            used.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
};