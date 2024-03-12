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
        for (int i = startIdx; i <= n; i++)
        {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
};