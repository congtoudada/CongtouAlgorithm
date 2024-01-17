#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> nums_set(nums1.begin(), nums1.end());
		unordered_set<int> result;
		for (auto iter = nums2.begin(); iter != nums2.end(); ++iter)
		{
			if (nums_set.find(*iter) != nums_set.end())
			{
				result.insert(*iter);
			}
		}
		return vector<int>(result.begin(), result.end());
    }
};
