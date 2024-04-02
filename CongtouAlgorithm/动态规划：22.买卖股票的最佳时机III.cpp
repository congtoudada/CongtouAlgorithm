#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(std::vector<int>& prices)
    {
	    //dp
	    //dp[i][0]：第i天，不操作（多余，可以不要）
	    //dp[i][1]：第i天，第一次持有
	    //dp[i][2]: 第i天，第一次不持有（相当于第一次卖出及以后）
	    //dp[i][3] : 第i天，第二次持有
	    //dp[i][4] : 第i天，第二次不持有
	    vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
	    //初始化
	    dp[0][0] = 0;
	    dp[0][1] = -prices[0];
	    dp[0][2] = 0;
	    dp[0][3] = -prices[0];
	    dp[0][4] = 0;
	    //遍历
		for (unsigned int i = 1; i < prices.size(); i++)
		{
			dp[i][0] = dp[i - 1][0]; //什么都不做
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]); //max(延续前一天状态，第一次买入)
			dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]); //max(延续前一天状态，第一次卖出)
			dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]); //max(延续前一天状态，第二次买入)
			dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]); //max(延续前一天状态，第二次卖出)
		}
		return dp[prices.size() - 1][4];
    }
};
