#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> abMap;
        int result = 0;
        for (auto num1 : nums1)
        {
	        for (auto num2 : nums2)
	        {
                abMap[num1 + num2]++;
	        }
        }
        for (auto num3 : nums3)
        {
	        for (auto num4 : nums4)
	        {
                int target = num3 + num4;
                if (abMap.find(-target) != abMap.end())
                {
                    result += abMap[-target];
                }
	        }
        }
        return result;
    }
};