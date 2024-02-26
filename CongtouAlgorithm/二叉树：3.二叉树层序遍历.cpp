#include <queue>
#include <vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> result;
        queue<TreeNode*> q;
        //规则：入队列不访问，出队列访问
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            result.push_back({});
            int idx = result.size() - 1;
            for (int i = 0; i < size; i++)
            {
                TreeNode* cur = q.front();
                q.pop();
                result[idx].push_back(cur->val);
                if (cur->left != nullptr)
                {
                    q.push(cur->left);
                }
                if (cur->right != nullptr)
                {
                    q.push(cur->right);
                }
            }
        }
        return result;
    }
};