#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct MyCompare
{
public:
    int operator()(int a, int b)
    {
        return a > b; //尾部pop的就是最小值，即获得小根堆
    }
};

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        //优先队列做法：更慢
        //priority_queue<int, vector<int>, MyCompare> pq(nums.begin(), nums.end());

        //for (int i = 0; i < k; i++)
        //{
        //    int minVal = pq.top();
        //    minVal = -minVal;
        //    pq.pop();
        //    pq.push(minVal);
        //}

        //int sum = 0;
        //while(!pq.empty())
        //{
        //    sum += pq.top();
        //    pq.pop();
        //}
        //return sum;

        //常规做法
        sort(nums.begin(), nums.end());
        //如果存在负数，优先把负数改为正数
        for (int i = 0; i < nums.size(); i++)
        {
            if (k == 0) break;
            if (nums[i] < 0)
            {
                nums[i] = -nums[i];
                k--;
            }
        }
        //如果全为正数且仍有余数，则只改第一个元素
        if (k > 0)
        {
            sort(nums.begin(), nums.end());
            for (int i = 0; i < k; i++)
            {
                nums[0] = -nums[0];
            }
        }
        //计算总和
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        return sum;
    }
};