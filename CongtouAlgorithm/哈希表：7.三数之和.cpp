#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] > 0) return result;
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			int left = i + 1, right = nums.size() - 1;
			while(left < right)
			{
				int sum = nums[i] + nums[left] + nums[right];
				if (sum > 0)
				{
					right--;
				}
				else if (sum < 0)
				{
					left++;
				}
				else
				{
					result.push_back({nums[i], nums[left], nums[right]});
					while (left < right && nums[left + 1] == nums[left]) left++; //去重
					while (left < right && nums[right] == nums[right - 1]) right--; //去重
					left++;
					right--;
				}
			}
		}
		return result;
    }
};
