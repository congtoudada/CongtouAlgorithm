#include <iostream>

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
    bool isValidBST(TreeNode* root) {
        TreeNode* pre = nullptr;
        return isValid(root, pre);
    }

    bool isValid(TreeNode* root, TreeNode* &pre)
    {
        if (root == nullptr) return true;
        if (!isValid(root->left, pre)) return false;
        if (pre != nullptr)
        {
	        if (root->val <= pre->val) //当前值小于pre值
	        {
                return false;
	        }
        }
        pre = root;
        if (!isValid(root->right, pre)) return false;
        return true;
    }
};

//int main()
//{
//    TreeNode* root = new TreeNode(1);
//    TreeNode* child = new TreeNode(1);
//    root->left = child;
//    Solution solution;
//    std::cout << solution.isValidBST(root) << std::endl;
//    return 0;
//}