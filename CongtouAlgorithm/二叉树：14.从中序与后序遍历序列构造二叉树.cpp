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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) return nullptr;
        //1.取根节点
        int val = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(val);
        if (postorder.size() == 1) return root;
        //2.切中序数组
        int idx;
        vector<int>::iterator iter = inorder.begin();
        for (idx = 0; idx < inorder.size(); idx++)
        {
            if (inorder[idx] == val) break;
            iter++;
        }
        vector<int> leftInorder(inorder.begin(), iter);
        vector<int> rightInorder(++iter, inorder.end());
        //3.切后序数组
        iter = postorder.begin();
        for (int i = 0; i < idx; i++)
        {
            iter++;
        }
        vector<int> leftPostorder(postorder.begin(), iter);
        vector<int> rightPostorder(iter, --postorder.end());
        //4.赋值
        root->left = buildTree(leftInorder, leftPostorder);
        root->right = buildTree(rightInorder, rightPostorder);
        return root;
    }
};

//int main()
//{
//    vector<int> inorder = { 9, 3, 15, 20, 7 };
//    vector<int> postorder = { 9, 15, 7, 20, 3 };
//    TreeNode* root = (new Solution())->buildTree(inorder, postorder);
//    return 0;
//}