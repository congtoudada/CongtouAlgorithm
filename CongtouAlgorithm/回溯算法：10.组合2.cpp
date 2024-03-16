#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<bool> used;
    vector<int> path;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            used.push_back(false);
        }
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return result;
    }

    //122
    //[]---->1------>12------->123------------------------------------>2------>22
    //0->1----->2------->3---------->2----->1----->0 for 1----->2------>3------->2--->1 for 2---->3
    void backtracking(const vector<int>& nums, int startIdx)
    {
        result.push_back(path);
        if (startIdx >= nums.size()) return;
        for (int i = startIdx; i < nums.size(); i++)
        {
	        if (i > 0 && nums[i] == nums[i-1] && used[i-1]==false)
                continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, i + 1);
            used[i] = false;
            path.pop_back();
        }
    }
};