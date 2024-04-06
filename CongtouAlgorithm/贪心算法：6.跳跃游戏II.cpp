#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int next_cover = 0; // 下一步覆盖最远距离下标
        int jump = 0; // 记录走的最大步数
        int cur_cover = 0; // 当前覆盖最远距离下标
        for (int i = 0; i <= next_cover; i++)
        {
            //更新覆盖范围
            next_cover = max(next_cover, i + nums[i]);
            if (i == cur_cover) //到达当前跳跃最大距离，记录一次跳跃
            {
                cur_cover = next_cover;
                jump++;
                if (cur_cover >= nums.size() - 1)
                    break;
            }
        }
        return jump;
    }
};