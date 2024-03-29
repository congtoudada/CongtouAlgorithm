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
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode* left, TreeNode* right)
    {
        if (left == nullptr && right != nullptr) return false;
        else if (left != nullptr && right == nullptr) return false;
        else if (left == nullptr && right == nullptr) return true;
        else if (left->val != right->val) return false;

        bool outside = isSymmetric(left->left, right->right);
        bool inside = isSymmetric(left->right, right->left);
        return outside && inside;
    }
};