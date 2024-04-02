#include <vector>
using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
		//dp:以i-1为结尾的text1和以j-1为结尾的text2的最长公共子序列长度
		vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));

		//递推公式
		// if(text1[i-1] == text2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
		// else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

		int result = 0;
		for (int i = 1; i <= (int)nums1.size(); i++)
		{
			for (int j = 1; j <= (int)nums2.size(); j++)
			{
				if (nums1[i - 1] == nums2[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
					if (dp[i][j] > result) result = dp[i][j];
				}
				else
				{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
				//cout << dp[i][j] << " ";
			}
			//cout << endl;
		}
		return result;
    }
};