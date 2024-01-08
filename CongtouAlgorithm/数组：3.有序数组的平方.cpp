#include <vector>

class Solution {
public:
	std::vector<int> sortedSquares(std::vector<int>& nums) {
		std::vector<int> result(nums.size());
		int k = nums.size() - 1;
		for (int i = 0, j = k; i <= j; )
		{
			if (nums[i] * nums[i] > nums[j] * nums[j])
			{
				result[k--] = nums[i] * nums[i];
				i++;
			}
			else
			{
				result[k--] = nums[j] * nums[j];
				j--;
			}
		}
		return result;
    }
};
