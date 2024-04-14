
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
    //0：无覆盖
    //1：有摄像头
    //2：有覆盖
    int traversal(TreeNode* root, int& result)
    {
        if (root == nullptr) return 2;
        int left = traversal(root->left, result);
        int right = traversal(root->right, result);
        //左右孩子都有覆盖，返回无覆盖。（让父节点装摄像头）
        if (left == 2 && right == 2) return 0;
        //左右孩子存在无覆盖，返回有摄像头。（在自身装摄像头）
        else if (left == 0 || right == 0)
        {
            result++;
            return 1;
        }
        //左右至少有一个摄像头，返回自身有覆盖
        else if (left == 1 || right == 1) return 2;
        //不会走到return -1，这里只是为语法需要
        return -1;
    }

    int minCameraCover(TreeNode* root) {
        int result = 0;
        if (traversal(root, result) == 0) result++;
        return result;
    }
};