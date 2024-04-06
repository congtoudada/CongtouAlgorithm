#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;
        int cover = 0;
        for (int i = 0; i <= cover; i++)
        {
            if (cover >= nums.size() - 1) return true;
            cover = max(cover, i + nums[i]);
        }
        return false;
    }
};