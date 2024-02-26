#include <algorithm>
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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left != nullptr && root->right == nullptr) //左子树不为空，右子树为空
        {
            return 1 + minDepth(root->left);
        }
        else if (root->left == nullptr && root->right != nullptr) //左子树为空，右子树不为空
        {
            return 1 + minDepth(root->right);
        }
        else //左右子树均不为空（或均为空）
        {
            return 1 + min(minDepth(root->left), minDepth(root->right));
        }
    }
};