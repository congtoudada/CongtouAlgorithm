#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        //dp[i][0]：第i天，持有股票最大利润；
        //dp[i][1]：第i天，不持有股票最大利润；
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i-1][1]-prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }

        return dp[dp.size() - 1][1];
    }
};
