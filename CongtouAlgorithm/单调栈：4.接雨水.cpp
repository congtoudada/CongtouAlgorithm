#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 1) return 0;
        int result = 0;
        stack<int> st;

        st.push(0);
        for (int i = 1; i < height.size(); i++)
        {
            if (height[i] <= height[st.top()])
            {
                st.push(i);
            }
            else if (height[i] > height[st.top()])
            {
                while (!st.empty() && height[i] > height[st.top()])
                {
                    int top = st.top();
                    st.pop();
                    //如果取出来的元素与当前栈顶元素相等，则重复取到最早放入的（没必要，如果相等高度差是0）
                    //while (!st.empty() && height[st.top()] == height[top])
                    //{
                    //    top = st.top();
                    //    st.pop();
                    //}

                    if (!st.empty())
                    {
                        int minVal = min(height[i], height[st.top()]);
                        int add = (minVal - height[top]) * (i - st.top() - 1);
                        result += add;
                        //cout << "add: " << top << " - " << add << endl;
                    }
                }
                st.push(i);
            }
        }
        return result;
    }
};

//int main()
//{
//    //vector<int> data = { 0,1,0,2,1,0,1,3,2,1,2,1 };
//    vector<int> data = { 4,2,0,3,2,5 };
//    Solution solution;
//    cout << solution.trap(data);
//}