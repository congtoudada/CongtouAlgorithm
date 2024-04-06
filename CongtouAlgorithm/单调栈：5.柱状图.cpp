#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        stack<int> st;
        vector<int> area(heights.size(), 0);
        st.push(0);
        area[0] += heights[0];

        for (int i = 1; i < heights.size(); i++)
        {
            area[i] += heights[i]; //当前元素至少为自身面积
            if (heights[i] > heights[st.top()])
            {
                st.push(i);
            }
            //如果要精确计算每个i的最大面积，而不是整体最大值需要用以下代码处理相等的情况
            //else if (heights[i] == heights[st.top()])
            //{
            //    //计算入栈元素左面积：不断取栈顶查看是否相等，是就加上自身值
            //}
            else
            {
                while (!st.empty() && heights[i] < heights[st.top()])
                {
                    //获取栈顶元素（比i大）
                    int top = st.top();
                    st.pop();
                    //计算栈顶元素的右面积
                    int right_area = heights[top] * (i - top - 1);
                    area[top] += right_area;
                }
                //计算当前元素的左面积
                if (st.empty()) //之前的元素均比i大
                {
                    area[i] += heights[i] * i;
                }
                else //存在<=i的元素
                {
                    area[i] += heights[i] * (i - st.top() - 1);
                }
                st.push(i);
            }
        }
        //未匹配的元素停留在栈内，依次取出计算
        while (!st.empty())
        {
            int top = st.top();
            st.pop();
            area[top] += (heights.size() - top - 1) * heights[top];
        }

        //找最大者
        for (int i = 0; i < area.size(); i++)
        {
            //cout << i << " : " << area[i] << endl;
            if (area[i] > result) result = area[i];
        }
        return result;
    }
};

//int main()
//{
//    //vector<int> data = { 0,1,0,2,1,0,1,3,2,1,2,1 };
//    vector<int> data = { 5, 5, 5, 4 };
//    Solution solution;
//    cout << solution.largestRectangleArea(data);
//}