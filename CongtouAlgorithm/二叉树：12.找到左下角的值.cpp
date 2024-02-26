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
    int findBottomLeftValue(TreeNode* root) {
        int depth = 1, maxDepth = 0, result = root->val;
        traversal(root, depth, maxDepth, result);
        return result;
    }

    void traversal(TreeNode* root, int depth, int& maxDepth, int& result)
    {
        if (root == nullptr) return;
        if (depth > maxDepth)
        {
            maxDepth = depth;
            result = root->val;
        }
        if (root->left)
        {
            traversal(root->left, depth+1, maxDepth, result);
        }
        if (root->right)
        {
            traversal(root->right, depth + 1, maxDepth, result);
        }
    }
};