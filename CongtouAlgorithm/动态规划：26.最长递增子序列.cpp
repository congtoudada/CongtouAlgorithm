#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //dp[i]: 以nums[i]为结尾的最长递增子序列长度
        vector<int> dp(nums.size(), 1);

        for (int i = 0; i < nums.size(); i++)
        {
	        for (int j = 0; j < i; j++)
	        {
		        if (nums[i] > nums[j])  //满足递增
		        {
					dp[i] = max(dp[i], dp[j] + 1);
		        }
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