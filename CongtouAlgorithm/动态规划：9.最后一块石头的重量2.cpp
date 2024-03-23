#include <vector>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int i = 0; i < stones.size(); i++)
        {
            sum += stones[i];
        }
        int target = sum / 2;
        int bag_weight = target;
        int prop_count = stones.size();

        //此题：重量 <=> 价值
        vector<int> dp(target+1, 0);
        for (int i = 0; i < prop_count; i++)
        {
	        for (int j = bag_weight; j >= 1; j--)
	        {
                if (j - stones[i] >= 0)  //能够放下stones[i]
					dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]); //取i与不取i选较大者
	        }
        }
        int result = dp[bag_weight];
        return sum - result - result;
    }
};