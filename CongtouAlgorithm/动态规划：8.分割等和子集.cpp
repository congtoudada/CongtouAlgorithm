#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if (sum % 2 == 1) return false; //奇数不可分割
        //此题：重量 == 价值
        int target = sum / 2;
        int bag_weight = target; //最多可以放个元素
        int prop_count = nums.size();

        ///一维dp做法（先物品，再倒序背包）
        vector<int> dp(bag_weight + 1, 0);
        for (int i = 0; i < prop_count; i++)
        {
            for (int j = bag_weight; j >= 1; j--)
            {
                if (j - nums[i] >= 0) //当前背包容量可以放下nums[i]
					dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);  //max(放i,不放i)
                if (dp[j] == target) return true;
            }
        }
        return false;
    }
};

//int main()
//{
//    Solution solution;
//    vector<int> input = { 1, 5, 11, 5 };
//   cout << solution.canPartition(input);
//}
