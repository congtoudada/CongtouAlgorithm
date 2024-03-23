#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //动规五部曲：
    //    1. dp[i]：输入数值i，有多少种二叉搜索树
    //    2. 递推公式：一共i个节点，取j为头节点。左孩子有j - 1个节点，右孩子有i - j个节点
    //    * ```c+ +
    //    for (int i = 1; i <= n; i++)
    //        for (int j = 1; j <= i; j++)
    //            dp[i] += dp[j - 1] * dp[i - j]
    //            ```
    //    3. dp初始化：`dp[0] = 1, dp[1] = 1`，其他初始化为0
    //    4. 遍历顺序：从小到大
    //    5. 打印dp数组
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        { 
	        for (int j = 1; j <= i; j++)
	        {
                dp[i] += dp[j - 1] * dp[i - j];
	        }
            cout << "dp[" << i << "]:" << dp[i] << endl;
        }
        return dp[n];
    }
};

//int main()
//{
//    Solution solution;
//    solution.numTrees(3);
//    return 0;
//}