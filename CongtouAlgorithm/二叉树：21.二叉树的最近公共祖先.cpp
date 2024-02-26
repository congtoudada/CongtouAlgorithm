
#include <cstddef>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //p 和 q 均存在于给定的二叉树中
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (root->val == p->val || root->val == q->val) return root; //存在符合p或q的节点，返回该节点
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left != nullptr && right != nullptr) return root;
        else if (left != nullptr && right == nullptr) return left;
        else if (left == nullptr && right != nullptr) return right;
        else return nullptr;
    }
};