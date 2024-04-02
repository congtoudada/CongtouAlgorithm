#include <vector>
using namespace std;

class Solution {
public:
    int rob(std::vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        int one_max = 0;
        int second_max = 0;

        //1.只考虑首元素
        for (unsigned int i = 2; i < nums.size() - 1; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        one_max = dp[dp.size() - 2];

        //2.只考虑尾元素
        fill(dp.begin(), dp.end(), 0);
        dp[1] = nums[1];
        dp[2] = max(nums[1], nums[2]);
        for (unsigned int i = 3; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        second_max = dp[dp.size() - 1];
        return max(one_max, second_max);
    }
};

//int main()
//{
//    Solution solution;
//    vector<int> data = { 1,2,3,1 };
//    solution.rob(data);
//    return 0;
//}