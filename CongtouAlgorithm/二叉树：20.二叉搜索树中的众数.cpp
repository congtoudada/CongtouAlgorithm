#include <vector>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        int minCount = INT_MIN;
        vector<int> result;
        int curVal = INT_MIN;
        int curCount = 0;
        traversal(root, minCount, result, curVal, curCount);
        return result;
    }

    void traversal(TreeNode* &root, int &minCount, vector<int> &result, 
        int &curVal, int &curCount)
    {
        if (root == nullptr) return;
        traversal(root->left, minCount, result, curVal, curCount);
        //频数统计
        if (curVal == root->val)
        {
            curCount++;
        }
        else
        {
            curCount = 1;
            curVal = root->val;
        }
        //结果处理
        if (minCount < curCount) //存在更高频的数
        {
            result.clear();
            result.push_back(root->val);
            minCount = curCount;
        }
        else if (minCount == curCount) //同频数
        {
            result.push_back(root->val);
        }
        traversal(root->right, minCount, result, curVal, curCount);
    }
};