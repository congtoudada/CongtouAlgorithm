#include "Cong.h"
class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		//dp[i][j]: 以i-1为结尾的text1，以j-1为结尾的text2构成的最长公共子序列
		vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));

		int result = 0;
		//从text1起始索引开始遍历
		for (int i = 1; i <= (int) text1.size(); i++)
		{
			//从text2起始索引开始遍历
			for (int j = 1; j <= (int) text2.size(); j++)
			{
				if (text1[i-1] == text2[j-1])
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

//int main()
//{
//	Solution solution;
//	solution.longestCommonSubsequence("abc", "def");
//	return 0;
//}