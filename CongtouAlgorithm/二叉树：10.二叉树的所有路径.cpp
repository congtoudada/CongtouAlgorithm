#include <vector>
#include <string>

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> result;
        traversal(root, path, result);
        return result;
    }

    void traversal(TreeNode* root, vector<int>& path, vector<string>& result)
    {
        path.push_back(root->val);
        //如果节点是叶子节点，就弹出，将路径并入结果集
        if (root->left == nullptr && root->right == nullptr)
        {
            result.push_back(getPathString(path));
            return;
        }
        if (root->left)
        {
            traversal(root->left, path, result);
            path.pop_back();
        }
        if (root->right)
        {
            traversal(root->right, path, result);
            path.pop_back();
        }
    }

    string getPathString(vector<int>& path)
    {
        string result;
        for (int i = 0; i < path.size(); i++)
        {
            result += std::to_string(path[i]);
            if (i != path.size() - 1)
                result += "->";
        }
        return result;
    }
};