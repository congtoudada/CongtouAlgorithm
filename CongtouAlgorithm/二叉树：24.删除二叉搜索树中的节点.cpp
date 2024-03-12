
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr; //情况1：没有找到key
        if (root->val == key)
        {
	        //情况2：删除节点正好是叶子节点
            if (root->left == nullptr && root->right == nullptr)
            {
                delete root;
                return nullptr; //返回给父节点
            }
            //情况3：删除只有一个孩子的父节点
            if (root->left != nullptr && root->right == nullptr)
            {
                TreeNode* child = root->left;
                delete root;
                return child;
            }
            if (root->left == nullptr && root->right != nullptr)
            {
                TreeNode* child = root->right;
                delete root;
                return child;
            }
            //情况4：删除具有两个孩子的父节点
            if (root->left != nullptr && root->right != nullptr)
            {
                //拿恰好比当前删除节点大的节点取代自己
				TreeNode* cur = root->right;
                while (cur->left != nullptr) cur = cur->left;
                cur->left = root->left;
                TreeNode* child = root->right;
                delete root;
                return child;
            }
        }
        if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else
        {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};