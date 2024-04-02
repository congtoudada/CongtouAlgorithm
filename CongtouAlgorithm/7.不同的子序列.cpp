#include "Cong.h"
class Solution {
public:
    int numDistinct(string s, string t) {
        //以i-1为尾的s，以j-1为尾的t中，s的子序列出现t的个数
        vector<vector<uint64_t>> dp(s.size() + 1, vector<uint64_t>(t.size() + 1, 0));
		//t为空串，每个s都应该包含，个数为1
		for (int i = 0; i <= (int) s.size(); i++)
		{
			dp[i][0] = 1;
		}
		
        for (int i = 1; i <= (int) s.size(); i++)
        {
	        for (int j = 1; j <= (int) t.size(); j++)
	        {
		        if (s[i-1] == t[j-1])
		        {
					//取s[i-1] + 不取s[i-1]
					dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		        }
				else
				{
					dp[i][j] = dp[i - 1][j];
				}
				//cout << dp[i][j] << " ";
	        }
			//cout << endl;
        }
		return dp[s.size()][t.size()];
    }
};

//int main()
//{
//	Solution solution;
//	solution.numDistinct("eee", "eee");
//	return 0;
//}