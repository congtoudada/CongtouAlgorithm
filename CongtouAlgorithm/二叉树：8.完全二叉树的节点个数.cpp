
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
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        TreeNode* leftChild = root->left;
        TreeNode* rightChild = root->right;
        int leftHeight = 0, rightHeight = 0;
        while(leftChild != nullptr)
        {
            leftChild = leftChild->left;
            leftHeight++;
        }
        while(rightChild != nullptr)
        {
            rightChild = rightChild->right;
            rightHeight++;
        }
        //如果是满二叉树，根据性质直接返回结果
        if (leftHeight == rightHeight) return (2 << leftHeight) - 1;

        int leftNum = countNodes(root->left);
        int rightNum = countNodes(root->right);
        return 1 + leftNum + rightNum;
    }
};