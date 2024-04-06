#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
		//dp[i][j]: [i,j]的回文子序列长度
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));

		for (int i = 0; i <s.size(); i++)
		{
			dp[i][i] = 1;
		}
		//遍历顺序：从下往上，从左往右
        for (int i = s.size()-1; i >= 0; i--)
        {
	        for (int j = i+1; j < s.size(); j++)
	        {
				if (s[i] == s[j])
				{
					dp[i][j] = dp[i + 1][j - 1] + 2;
				}
				else
				{
					dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
				}
	        }
        }
		return dp[0][s.size() - 1];
    }
};