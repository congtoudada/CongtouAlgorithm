#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> window(k);
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            //1.滑动窗口移动导致元素弹出
            if (!window.empty() && i>=k && nums[i - k] == window.front())
            {
                window.pop_front();
            }
                
	        //2.添加新元素：将<=当前值的元素从队头或队尾弹出
            while (!window.empty() && window.front() < nums[i])
            {
                window.pop_front();
            }
            while (!window.empty() && window.back() < nums[i])
            {
                window.pop_back();
            }
            window.push_back(nums[i]);

            //取最大元素
            if (i>=k-1)
				result.push_back(window.front());
        }
        return result;
    }
};