#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 0, 1);
        return result;
    }

    void backtracking(int k, int targetSum, int sum, int startIdx)
    {
        if (sum > targetSum) return;  //剪枝1：sum>targetSum
	    if (k == path.size() && sum == targetSum)
	    {
            result.push_back(path);
            return;
	    }
        //剪枝2：剩余元素不足矣构成k个
        // (k - path.size()) 最多还能再放几个数
        // 10 - i <= k - path.size()
        // k = 2, path.size() = 0, i至多为8
        for (int i = startIdx; i <= 10 - (k - path.size()); i++)
        {
            sum += i;
            path.push_back(i);
            backtracking(k, targetSum, sum, i + 1);
            path.pop_back();
            sum -= i;
        }
    }
};