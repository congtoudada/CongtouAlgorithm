#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }

    void backtracking(int n, int k, int startIdx)
    {
        //终止条件
        if (path.size() == k)
        {
            result.push_back(path);
            return;
        }
        //单层逻辑
        //每次递归如果n-startIdx+path.size()+1不足k，则说明剩余元素不足以构成k，直接剪枝
        for (int i = startIdx; n - i + path.size() + 1 >= k; i++)
        {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
};