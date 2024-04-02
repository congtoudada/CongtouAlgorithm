#include "Cong.h"

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        //dp[i][j]: 以i-1结尾的nums1，以j-1为结尾的nums2，最长重复子数组长度
        //（dp[i][j]对应nums的i-1,j-1）
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1, 0));

        int result = 0;
        for (int i = 1; i <= (int)nums1.size(); i++)
        {
            for (int j = 1; j <= (int) nums2.size(); j++)
            {
	            if (nums1[i-1] == nums2[j-1])
	            {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    if (dp[i][j] > result) result = dp[i][j];
	            }
            }
        }
        return result;
    }
};
