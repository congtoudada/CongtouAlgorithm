#include "Cong.h"
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));
		//假设word1是空串，word2需全部删除
		for (int j = 1; j <= (int) word2.size(); j++)
		{
			dp[0][j] = j;
		}
		//反之同理
		for (int i = 1; i <= (int) word1.size(); i++)
		{
			dp[i][0] = i;
		}
		dp[0][0] = 0;

        for (int i = 1; i <= (int) word1.size(); i++)
        {
	        for (int j = 1; j <= (int) word2.size(); j++)
	        {
				//如果两者相同，则不发生删除操作
		        if (word1[i-1] == word2[j-1])
		        {
					dp[i][j] = dp[i - 1][j - 1];
		        }
				else
				{
					// min(删除word1+1, 删除word2+1, 删除word1和word2+2)
					dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
					dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 2);
				}
	        }
        }
		return dp[word1.size()][word2.size()];
    }
};