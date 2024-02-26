#include <stack>
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
    //前序遍历
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        st.push(root);
        while (!st.empty())
        {
            TreeNode* node = st.top();
            st.pop();
            if (node != nullptr) result.push_back(node->val);
            else continue;

            //先入栈右孩子，这样才能先遍历左孩子
            st.push(node->right);
            st.push(node->left);
        }
        return result;
    }

    //后序遍历
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        st.push(root);
        while (!st.empty())
        {
            TreeNode* node = st.top();
            st.pop();
            if (node != nullptr) result.push_back(node->val);
            else continue;

            st.push(node->left);
            st.push(node->right);

        }
        reverse(result.begin(), result.end());
        return result;
    }

    //中序遍历
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(cur != nullptr || !st.empty())
        {
            //把所有左孩子入栈（包括根）
	        if (cur != nullptr)
	        {
                st.push(cur);
                cur = cur->left;
	        }
            else //所有左孩子遍历结束，开始取元素访问
            {
                cur = st.top();
                st.pop();
                result.push_back(cur->val);
                cur = cur->right; //指向右孩子（如果存在，后续会先将右孩子及右孩子的所有左孩子入栈）
            }
        }
        return result;
    }
};
