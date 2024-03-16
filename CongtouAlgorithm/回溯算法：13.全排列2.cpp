#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> used;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
            used.push_back(false);
        backtracking(nums);
        return result;
    }

    void backtracking(const vector<int>& nums)
    {
	    if (nums.size() == path.size())
	    {
            result.push_back(path);
            return;
	    }
        for (int i = 0; i < nums.size(); i++)
        {
            //跳过已经取过的索引
            if (used[i] == true) continue;
	        //树层去重
            if (i > 0 && nums[i] == nums[i-1] && used[i-1] == false)
                continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums);
            path.pop_back();
            used[i] = false;
        }
    }
};