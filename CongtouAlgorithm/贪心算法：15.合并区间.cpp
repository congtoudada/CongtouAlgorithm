#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b)
            {
                return a[0] < b[0];
            });
        for (int i = 1; i < intervals.size(); i++)
        {
	        if (intervals[i][0] <= intervals[i-1][1]) //区间重叠，需要合并
	        {
                intervals[i][1] = max(intervals[i][1], intervals[i - 1][1]);
                intervals[i][0] = min(intervals[i][0], intervals[i - 1][0]);
	        }
            else
            {
                result.push_back({ intervals[i - 1][0], intervals[i - 1][1] });
            }
        }
        result.push_back({ intervals[intervals.size() - 1][0], intervals[intervals.size() - 1][1] });
        return result;
    }
};