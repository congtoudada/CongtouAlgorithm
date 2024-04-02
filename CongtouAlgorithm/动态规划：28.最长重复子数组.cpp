#include <vector>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        //以i-1为结尾的nums1和以j-1为结尾的nums2的最长重复子数组
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));

        int result = 0;
        for (int i = 1; i <= static_cast<int>(nums1.size()); i++)
        {
            for (int j = 1; j <= static_cast<int>(nums2.size()); j++)
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
