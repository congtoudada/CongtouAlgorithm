#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        //动规五部曲：
        //    1. dp[i]：达到第i阶有dp[i]种方法
        //    2. 递推公式：`dp[i] = dp[i - 1] + dp[i - 2]`
        //    3. dp数组初始化：`dp[1] = 1, dp[2] = 2`
        //    4. 遍历顺序：从前向后
        //    5. 打印dp数组

        //本质是斐波那契，直接压缩状态（用vector会overflow）
        //vector<int> dp(2);
        //dp[0] = 1; //实际表示走1阶走法
        //dp[1] = 2; //实际表示走2阶走法
        //if (n <= 2) return dp[n - 1];
        //for (int i = 3; i <= n; i++)
        //{
        //    int sum = dp[i - 1] + dp[i - 2];
        //    dp[0] = dp[1];
        //    dp[1] = sum;
        //}
        //return dp[1];

        if (n == 1) return 1;
        if (n == 2) return 2;
        int stateA = 1; //实际表示走1阶走法
        int stateB = 2; //实际表示走2阶走法
        for (int i = 3; i <= n; i++)
        {
            int curState = stateA + stateB;
            stateA = stateB;
            stateB = curState;
        }
        return stateB;
    }
};