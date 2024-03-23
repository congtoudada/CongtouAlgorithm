#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //动规五部曲：
	//    1. `dp[i][j]`：到ij位置有多少种不同的路径
	//    2. 递归公式：
	//    * ```c+ +
	//    if (obs[i][j] == 0) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
	//      ```
	//    3. dp初始化：dp全部初始化为0，边缘没有障碍才为1。如果起点或终点有障碍，记得return0
	//    * ```c+ +
	//    for (int i = 0; i < m && obs[i][0] == 0; i++) dp[i][0] = 1;
	//    for (int j = 0; j < n && obs[0][j] == 0; j++) dp[0][j] = 1;
	//      ```
	//    4. 遍历顺序：从左到右，从上到下
	//    5. 打印dp数组
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        //起点或终点有障碍，直接return0
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
		vector<vector<int>> dp(m, vector<int>(n, 0)); //全部初始化为0
		for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
		for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				if (obstacleGrid[i][j] == 0)
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
					//cout << "dp[" << i << "][" << j << "]:" << dp[i][j] << endl;
			}
		}
		return dp[m - 1][n - 1];
    }
};

//int main()
//{
//	vector<vector<int>> obstacleGrid = {
//		{0, 0, 0},
//		{0, 1, 0},
//		{0, 0, 0}
//	};
//	Solution solution;
//	solution.uniquePathsWithObstacles(obstacleGrid);
//	return 0;
//}
