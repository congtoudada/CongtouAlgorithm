#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        //动规五部曲：
        //    1. `dp[i][j]`：到ij位置有多少种不同的路径
        //    2. 递推公式：`dp[i][j] = dp[i - 1][j] + dp[i][j - 1]`
        //    3. 初始化dp：`dp[0][j] = 1, dp[i][0] = 1`
        //    4. 遍历顺序：从左往右，从上往下
        //    5. 打印dp数组
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            dp[i][0] = 1;
        for (int j = 0; j < n; j++)
            dp[0][j] = 1;
        for (int i = 1; i < m; i++)
        {
	        for (int j = 1; j < n; j++)
	        {
                //从上或从左边走到ij
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
	        }
        }
        return dp[m - 1][n - 1];
    }
};