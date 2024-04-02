#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //dp:以i-1为结尾的text1和以j-1为结尾的text2的最长公共子序列长度
		vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));

		//递推公式
		// if(text1[i-1] == text2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
		// else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

		int result = 0;
        for (int i = 1; i <= (int) text1.size(); i++)
        {
	        for (int j = 1; j <= (int) text2.size(); j++)
	        {
				if (text1[i - 1] == text2[j - 1])
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
//	solution.longestCommonSubsequence("abcde", "ace");
//	return 0;
//}