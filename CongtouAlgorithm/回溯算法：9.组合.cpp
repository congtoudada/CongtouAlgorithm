#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
        return result;
    }
    void backtracking(const vector<int>& nums, int startIdx)
    {
        result.push_back(path);
        if (startIdx >= nums.size()) return;
	    for (int i = startIdx; i < nums.size(); i++)
	    {
		    path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
	    }
    }
};