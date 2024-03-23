#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        //顺序遍历物品
        for (int i = 0; i < strs.size(); i++)
        {
	        //统计物品重量
            int x = 0; //0的个数
            int y = 0; //1的个数
            for (auto c : strs[i])
            {
                if (c == '0') x++;
                else y++;
            }
            //倒序遍历背包
            for (int j = m; j >= x; j--)
            {
	            for (int k = n; k >= y; k--)
	            {
		            //递推公式：max(不取当前字符串, 取当前字符串)
                    dp[j][k] = max(dp[j][k], dp[j - x][k - y] + 1);
	            }
            }
            ////打印dp数组
            //cout << "consider string: " << strs[i] << ":" << endl;
            //for(int j = 0; j <= m; j++)
            //{
            //    for (int k = 0; k <= n; k++)
            //    {
            //        cout << dp[j][k] << " ";
            //    }
            //    cout << endl;
            //}
            //cout << "-------------------------------------------------------" << endl;
        }

        return dp[m][n];
    }
};

//int main()
//{
//    Solution solution;
//    vector<string> data = { "10", "0001", "111001", "1", "0" };
//    solution.findMaxForm(data, 5, 3);
//    return 0;
//}