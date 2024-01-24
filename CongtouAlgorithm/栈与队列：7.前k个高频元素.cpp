#include <iostream>
#include <ostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    // 小顶堆
    class mycomparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //1.统计频率
        unordered_map<int, int> countMap;
        for (auto num : nums)
            countMap[num]++;

        //2.使用优先级队列
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
        for (auto pair : countMap)
        {
            pri_que.push(pair);
            if (pri_que.size() > k)
                pri_que.pop();
        }

        //3.返回结果
        vector<int> result;
        while(!pri_que.empty())
        {
            result.push_back(pri_que.top().first);
            pri_que.pop();
        }
        return result;
    }
};

//int main()
//{
//    Solution solution;
//    vector<int> vec = { 1, 1, 1, 2, 2, 3 };
//    for (auto item : solution.topKFrequent(vec,  2))
//    {
//        cout << item << endl;
//    }
//    return 0;
//}