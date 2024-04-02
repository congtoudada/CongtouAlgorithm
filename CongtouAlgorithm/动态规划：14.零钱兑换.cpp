#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //动规五部曲：
        //    1. dp[j]：组成重量为amount背包的最少个数为dp[j]
        //    2. 递推公式：`dp[j] = min(dp[j - coins[i]] + 1, dp[j])`
        //    3. dp初始化：全0
        //    4. 遍历顺序：先物品，再背包（求组合数）
        //    5. 打印dp数组
        vector<int> dp(amount + 1, INT_MAX - 1);
        dp[0] = 0;
        for (int i = 0; i <coins.size(); i++)
        {
	        for (int j = coins[i]; j <= amount; j++)
	        {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
	        }
            //for (int i = 0; i < dp.size(); i++)
            //{
            //    cout << dp[i] << " ";
            //}
            //cout << endl;
        }
        if (dp[amount] == INT_MAX - 1) return -1;
        return dp[amount];
    }
};

//int main()
//{
//    Solution solution;
//    vector<int> data = { 1, 2 };
//    solution.coinChange(data, 3);
//    return 0;
//}