#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(), 0);
        stack<int> st;
        st.push(0);
        for (int i = 0; i < temperatures.size(); i++)
        {
            if (temperatures[i] <= temperatures[st.top()])
            {
                st.push(i);
            }
            else
            {
	            while (!st.empty() && temperatures[i] > temperatures[st.top()])
	            {
                    answer[st.top()] = i - st.top();
                    st.pop();
	            }
                st.push(i);
            }
        }
        return answer;
    }
};