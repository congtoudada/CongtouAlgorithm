#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));

        int result = 0;
        for (int i = 1; i <= (int) s.size(); i++)
        {
	        for (int j = 1; j <= (int) t.size(); j++)
	        {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    if (dp[i][j] > result) result = dp[i][j];
                }
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                //剪枝: dp[i][j] = dp[i][j-1]; //因为如果j的长度比i小的序列是绝对不可能的
	        }
        }
        return result == s.size();
    }
};
