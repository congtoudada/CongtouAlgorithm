#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());

        dp[0] = nums[0];
        int result = nums[0];
        for (int i = 1; i < (int) dp.size(); i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            //cout << dp[i] << " " << endl;
            if (dp[i] > result) result = dp[i];
        }
        return result;
    }

    //int maxSubArray(vector<int>& nums) {
    //    if (nums.size() == 1) return nums[0];
    //    //dp[i]: 以i-1为结尾的最大子数组和
    //    //dp[i][0]: 取
    //    //dp[i][1]: 不取
    //    vector<vector<int>> dp(nums.size(), vector<int>(2));
    //    //递推公式：
    //    //      dp[i][0] = max(dp[i-1][0] + nums[i], nums[i]); //max(顺取，只取nums[i])
    //    //      dp[i][1] = max(dp[i-1][1], dp[i-1][0]); //max(依旧不取，上一次取了这次不取)
    //    //初始化: dp[0] = 0;
    //    dp[0][0] = nums[0];
    //    dp[0][1] = nums[0];
    //    //int result = nums[0];
    //    for (int i = 1; i < (int) nums.size(); i++)
    //    {
    //        dp[i][0] = max(dp[i - 1][0] + nums[i], nums[i]); //max(顺取，只取nums[i])
    //        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0]); //max(依旧不取，上一次取了这次不取)
    //        //int temp = max(dp[i][0], dp[i][1]);
    //        //if (temp > result) result = temp;
    //        //cout << dp[i][0] << " " << dp[i][1] << endl;
    //    }
    //    return max(dp[dp.size()-1][0], dp[dp.size()-1][1]);
    //}
};

//int main()
//{
//    Solution solution;
//    vector<int> data = { -2,1,-3,4,-1,2,1,-5,4 };
//    solution.maxSubArray(data);
//    return 0;
//}