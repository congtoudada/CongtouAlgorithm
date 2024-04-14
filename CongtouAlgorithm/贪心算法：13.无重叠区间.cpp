#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //根据左区间排序
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b)
            {
                return a[0] < b[0];
            });

        int result = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            //如果下一个元素的左区间 < 上一个元素的右区间，发生重叠，选择较小右区间保留
	        if (intervals[i][0] < intervals[i-1][1])
	        {
                result++;
                intervals[i][1] = min(intervals[i - 1][1], intervals[i][1]);
	        }
        }
        return result;
    }
};