#include <vector>
using namespace std;

class Solution {
public:
    int fib(int n) {
        //1. dp[i]：第i个斐波那契数值为dp[i]
        //2. 递推公式：题目已给出`dp[i] = dp[i - 1] + dp[i - 2]`
        //3. dp数组如何初始化：`dp[0] = 0, dp[1] = 1`
        //4. 确定遍历顺序：从小到大遍历（从前向后）
        //5. 打印dp数组
        //vector<int> dp(n);
        //dp[0] = 0;
        //dp[1] = 1;
        //for (int i = 2; i <= n; i++)
        //{
        //    dp[i] = dp[i - 1] + dp[i - 2];
        //}

        //状态压缩
        vector<int> dp(2);
        dp[0] = 0;
        dp[1] = 1;
        if (n <= 1) return dp[n];
        int sum = 0;
        for (int i = 2; i <= n; i++)
        {
            sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return sum;
    }
};