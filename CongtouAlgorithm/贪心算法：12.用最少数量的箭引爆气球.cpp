#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b)
            {
                return a[0] < b[0]; //根据左边界升序
            });

        int result = 0;
        for (int i = 1; i < points.size(); i++)
        {
	        if (points[i][0] > points[i-1][1]) //当前左边界大于上一个右边界，必须射箭
	        {
                result++;
	        }
            else
            {
                //当前左边界与上一个右边界重叠，则取最小右边界
                points[i][1] = min(points[i - 1][1], points[i][1]);
            }
        }
        result++; //最后一箭
        return result;
    }
};