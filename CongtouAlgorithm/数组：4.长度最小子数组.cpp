#include <vector>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int i = 0;
        int result = std::numeric_limits<int>::max();
        int sum = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            sum += nums[j];
            while(sum >= target)
            {
                int subL = j - i + 1;
                result = std::min(result, subL);
                sum -= nums[i++];
            }
        }
        if (result == std::numeric_limits<int>::max()) result = 0;
        return result;
    }
};
