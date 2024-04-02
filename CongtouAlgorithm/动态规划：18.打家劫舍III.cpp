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
    int rob(TreeNode* root) {
        auto dp = robTree(root);
        return max( dp[0], dp[1] );
    }

    vector<int> robTree(TreeNode* node)
    {
        //dp: {不偷, 偷}
        if (node == nullptr) return { 0, 0 };
        vector<int> leftdp = robTree(node->left);
        vector<int> rightdp = robTree(node->right);

        int no_rob = max(leftdp[0], leftdp[1]) + max(rightdp[0], rightdp[1]); //不偷
        int ok_rob = leftdp[0] + rightdp[0] + node->val; //偷
        return { no_rob, ok_rob };
    }
};