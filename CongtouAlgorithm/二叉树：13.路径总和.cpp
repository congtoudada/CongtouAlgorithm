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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        return traversal(root, targetSum - root->val);
    }

    bool traversal(TreeNode* root, int count)
    {
	    if (root->left == nullptr && root->right == nullptr)
	    {
            if (count == 0) return true;
            else return false;
	    }
        if (root->left)
        {
            if (traversal(root->left, count - root->left->val)) return true;
        }
        if (root->right)
        {
            if (traversal(root->right, count - root->right->val)) return true;
        }
        return false;
    }
};