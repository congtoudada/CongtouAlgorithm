#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(int k, vector<int>& prices)
	{
		//dp
		//dp[i][0]：第i天，不操作（多余，可以不要）
		//dp[i][1]：第i天，第一次持有
		//dp[i][2]: 第i天，第一次不持有（相当于第一次卖出及以后）
		//dp[i][3] : 第i天，第二次持有
		//dp[i][4] : 第i天，第二次不持有
		vector<vector<int>> dp(prices.size(), vector<int>(2*k+1, 0));
		//初始化
		for (int j = 0; j < 2*k+1; j++)
		{
			if (j % 2 == 0)
				dp[0][j] = 0;
			else
				dp[0][j] = -prices[0];
		}
		//遍历
		for (unsigned int i = 1; i < prices.size(); i++)
		{
			for (int j = 1; j < 2*k; j += 2)  //第j/2次买入
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]); //max(延续前一天状态，当天买入)
				dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] + prices[i]); //max(延续前一天状态，当天卖出)
			}
		}
		return dp[prices.size() - 1][2*k];
	}
};
