#include "Cong.h"

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		//dp[i]: 以i为结尾的最长递增子序列长度
		vector<int> dp(nums.size(), 1);
		int result = 1;
		for (int i = 1; i < dp.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
				if (dp[i] > result) result = dp[i];
				//cout << dp[i] << " ";
			}
		}
		return result;
	}
};

//int main()
//{
//	Solution solution;
//	vector<int> data = { 10,9,2,5,3,7,101,18 };
//	solution.lengthOfLIS(data);
//	return 0;
//}