#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            int diff = target - nums[i];
            if (map.find(diff) != map.end())
            {
                return move(vector<int>(2) = { map[diff], i });
            }
            map.insert(make_pair(nums[i], i));
        }
        return {};
    }
};
