#include "Cong.h"
class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		vector<int> dp(nums.size(), 1);

		int result = 1;
		for (unsigned int i = 1; i < nums.size(); i++)
		{
			if (nums[i] > nums[i - 1])
			{
				dp[i] = dp[i - 1] + 1;
				if (dp[i] > result) result = dp[i];
			}
		}
		return result;
	}
};

//int main()
//{
//	Solution solution;
//	vector<int> data = { 1,3,5,4,7 };
//	solution.findLengthOfLCIS(data);
//	return 0;
//}