#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //left + right = sum
        //left - right = target
        //==>left = (sum + target) / 2
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if (abs(target) > sum) return 0; //没考虑到！
        if ((sum + target) % 2 == 1) return 0;
        int bag_weight = (sum + target) / 2;
        //dp
        //dp[j]: 容量为j的背包，有dp[j]种方式装满
        vector<int> dp(bag_weight+1, 0);
        //初始化
        dp[0] = 1;

        //递推公式：dp[j] = dp[j] + dp[j - nums[i]]
        //遍历
        for (int i = 0; i < nums.size(); i++)
        {
            //这里是j>=nums[i]，不是1！确实只有背包重量>=物品重量才有更新的可能性
	        for (int j = bag_weight; j >= nums[i]; j--) 
	        {
                if (j - nums[i] >= 0)
					dp[j] = dp[j] + dp[j - nums[i]];
	        }
            //for (int item : dp)
            //{
            //    cout << item << " ";
            //}
            //cout << endl;
        }
        return dp[bag_weight];
    }
};

//int main()
//{
//    Solution solution;
//    vector<int> data = { 0,0,0,0,0,0,0,0,1 };
//    solution.findTargetSumWays(data, 1);
//    return 0;
//}