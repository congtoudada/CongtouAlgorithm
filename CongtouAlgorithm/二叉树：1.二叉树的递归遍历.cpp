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
    //前序遍历
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorderTraversal(root, result);
        return result;
    }

    void preorderTraversal(TreeNode* root, vector<int>& result)
    {
        if (root == nullptr) return;
        result.push_back(root->val);
        preorderTraversal(root->left, result);
        preorderTraversal(root->right, result);
    }

    //中序遍历
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderTraversal(root, result);
        return result;
    }

    void inorderTraversal(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;
        inorderTraversal(root->left, result);
        result.push_back(root->val);
        inorderTraversal(root->right, result);
    }

    //后序遍历
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorderTraversal(root, result);
        return result;
    }

    void postorderTraversal(TreeNode* root, vector<int>& result)
    {
        if (root == nullptr) return;
        postorderTraversal(root->left, result);
        postorderTraversal(root->right, result);
        result.push_back(root->val);
    }
};