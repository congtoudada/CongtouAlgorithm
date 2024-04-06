#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);
        stack<int> st;
        unordered_map<int, int> relation;

        st.push(0);
        for (int i = 0; i < nums2.size(); i++)
        {
	        if (nums2[i] < nums2[st.top()])
	        {
                st.push(i);
	        }
            else
            {
	            while(!st.empty() && nums2[i] > nums2[st.top()])
	            {
                    relation.emplace(nums2[st.top()], nums2[i]);
                    st.pop();
	            }
                st.push(i);
            }
        }

        for (int i = 0; i < nums1.size(); i++)
        {
            if (relation.find(nums1[i]) != relation.end())
            {
                ans[i] = relation[nums1[i]];
            }
        }
        return ans;
    }
};