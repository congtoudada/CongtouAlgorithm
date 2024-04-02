#include <vector>
using namespace std;

class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		//dp[i]: 以nums[i]为结尾的最长递增子序列长度
		vector<int> dp(nums.size(), 1);

		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] > nums[i-1])  //满足递增
			{
				dp[i] = dp[i-1] + 1;
			}
		}

		int maxVal = 1;
		for (int i = 0; i < dp.size(); i++)
		{
			if (dp[i] > maxVal)
				maxVal = dp[i];
		}
		return maxVal;
	}
};