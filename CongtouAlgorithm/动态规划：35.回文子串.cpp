#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int countSubstrings(string s) {
		//[i, j]子串是否是回文子串
		vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
		int result = 0;
		//遍历顺序：从下往上，从左往右
		for (int i = s.size() - 1; i >= 0; i--)
		{
			for (int j = i; j < s.size(); j++)
			{
				if (s[i] == s[j])
				{
					if (j - i <= 1)
					{
						dp[i][j] = true;
						result++;
					}
					else if (dp[i + 1][j - 1] == true)
					{
						dp[i][j] = true;
						result++;
					}
				}
			}
		}
		return result;
	}
};