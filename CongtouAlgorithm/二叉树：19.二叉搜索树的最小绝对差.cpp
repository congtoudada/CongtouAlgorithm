#include <climits>

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
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
        TreeNode* pre = nullptr;
        traversal(root, pre, minDiff);
        return minDiff;
    }

    void traversal(TreeNode* &root, TreeNode* &pre, int &minDiff)
    {
        if (root == nullptr) return;
        traversal(root->left, pre, minDiff);
        if (pre != nullptr)
        {
	        if (root->val - pre->val < minDiff)
	        {
                minDiff = root->val - pre->val;
	        }
        }
        pre = root;
        traversal(root->right, pre, minDiff);
    }
};