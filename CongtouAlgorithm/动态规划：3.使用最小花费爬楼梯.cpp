#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //动规五部曲：
        //    1. dp[i]：到达i位置花费为dp[i]
        //    2. 递推公式：`dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2])`
        //    3. 初始化dp：`dp[0] = 0, dp[1] = 0`（起点不花钱）
        //    4. 遍历顺序：从前往后
        //    5. 打印dp数组

        vector<int> dp(cost.size()+1);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i < dp.size(); i++)
        {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
            //std::cout << "dp[" << i << "]: " << dp[i] << endl;
        }
        return dp[cost.size()];
    }
};

//int main()
//{
//    Solution solution;
//    vector<int> cost = { 10, 15, 20 };
//    solution.minCostClimbingStairs(cost);
//    return 0;
//}