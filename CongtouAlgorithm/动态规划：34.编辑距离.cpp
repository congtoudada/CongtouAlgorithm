#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        //以i-1为结尾的word1和与j-1结尾的word2最小距离
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));
        //dp初始化
        dp[0][0] = 0; //word1和word2全空
        for (int i = 1; i <= word1.size(); ++i) //假设word2为空
        {
            dp[i][0] = i;
        }
        for (int j = 0; j <= word2.size(); ++j) //假设word1为空
        {
            dp[0][j] = j;
        }

        for (int i = 1; i <= word1.size(); i++)
        {
            for (int j = 1; j <= word2.size(); j++)
            {
	            if (word1[i-1] == word2[j-1])
	            {
                    dp[i][j] = dp[i - 1][j - 1];
	            }
                else
                {
                    //min(删掉word1字符，删掉word2字符，替换word1字符为word2字符）
                    dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};