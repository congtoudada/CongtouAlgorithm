#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if (nums.size() == 1) return { -1 };
        vector<int> result(nums.size(), -1);
        stack<int> st;

        st.push(0);
        int i = 1;
        for(int i = 0; i < nums.size() * 2; i++)
        {
            int idx = i % nums.size();
            if (nums[idx] <= nums[st.top()])
            {
                st.push(idx);
            }
            else
            {
                while (!st.empty() && nums[idx] > nums[st.top()])
                {
                    result[st.top()] = nums[idx];
                    st.pop();
                }
                st.push(idx);
            }
        }
        return result;
    }
};