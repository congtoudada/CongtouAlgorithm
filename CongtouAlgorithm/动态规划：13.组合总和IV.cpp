#include <vector>
using namespace std;

class Solution {
public:
    int combinationSum4(std::vector<int>& nums, int target) {
        vector<unsigned> dp(target + 1, 0); //装满重量为amount的背包有多少种方法
        dp[0] = 1;

        for (int j = 0; j <= target; j++)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (j - nums[i] >= 0)
                    dp[j] = dp[j] + dp[j - nums[i]];
            }
        }
        return dp[target];
    }
};
