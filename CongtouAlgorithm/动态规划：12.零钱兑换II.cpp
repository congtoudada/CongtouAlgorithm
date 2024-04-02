#include <vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins)
    {
        //动规五部曲：
        //    1. dp[j]：装满背包容量为j的背包，有多少种方法，即`dp[amount]`
        //    2. 递推公式：`dp[j] = dp[j] + dp[j - coins[i]]`
        //    3. 初始化：`dp[0] = 1`，其余为0
        //    4. 遍历顺序：先物品，再背包（组合问题，排列问题反之）
        //      * 先物品，就只可能先放物品1，再放物品2，不会出现21
        //    5. 打印dp数组
	    vector<int> dp(amount+1, 0); //装满重量为amount的背包有多少种方法
        dp[0] = 1;

        for (int i = 0; i < coins.size(); i++)
        {
	        for (int j = 0; j <= amount; j++)
	        {
                if (j - coins[i] >= 0)
					dp[j] = dp[j] + dp[j - coins[i]];
	        }
        }
        return dp[amount];
    }
};