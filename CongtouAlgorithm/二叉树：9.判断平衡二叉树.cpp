
#include <valarray>

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
    bool isBalanced(TreeNode* root) {
        return !(getHeight(root) == -1);
    }

    int getHeight(TreeNode* root)
    {
        if (root == nullptr) return 0;
        int leftHeight = getHeight(root->left);
        if (leftHeight == -1) return -1; //左子树不平衡
        int rightHeight = getHeight(root->right);
        if (rightHeight == -1) return -1; //右子树不平衡
        //当前树
        int result;
        if (std::abs(leftHeight - rightHeight) > 1)
            result = -1;
        else
            result = 1 + std::max(leftHeight, rightHeight); //当前深度
        return result;
    }
};