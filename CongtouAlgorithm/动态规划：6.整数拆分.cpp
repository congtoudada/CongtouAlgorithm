#include <vector>
using namespace std;

class Solution {
public:
    //动规五部曲：
    //    1. dp[i]：给定数i，拆分后得到的最大乘积为dp[i]
    //    2. 递推公式：`dp[i] = max(j * (i - j), j * dp[i - j], dp[i])`（j = 1; j <= i / 2)
    //    * 拆成2个：j, i - j
    //    * 拆成3个及以上：j, dp[i - j]
    //    * 不同拆法之间比较：dp[i]
    //    3. 初始化dp：`dp[0] = 0, dp[1] = 0, dp[2] = 1`
    //    4. 遍历顺序：从小到大(i = 3开始)
    //    5. 打印dp数组
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
	        for (int j = 1; j <= i / 2; j++)
	        {
                dp[i] = max(max(j * (i - j), j * dp[i - j]), dp[i]);
	        }
        }
        return dp[n];
    }
};