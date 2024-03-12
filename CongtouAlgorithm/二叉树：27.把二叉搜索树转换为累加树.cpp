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
    TreeNode* convertBST(TreeNode* root) {
        int pre = 0;
        traversal(root, pre);
        return root;
    }

    void traversal(TreeNode* root, int& pre)
    {
        if (root == nullptr) return;
        traversal(root->right, pre);
        root->val += pre;
        pre = root->val;
        traversal(root->left, pre);
    }
};