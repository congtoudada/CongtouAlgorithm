#include <vector>
#include <iostream>
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return count(nums, 0, nums.size()); //左闭右开
    }

    TreeNode* count(vector<int>& nums, int start, int end)
    {
	    if (end - start <= 1)
	    {
            return new TreeNode(nums[start]);
	    }
        int maxValue = INT_MIN;
        int maxIndex;
        for (int i = start; i < end; i++)
        {
	        if (nums[i] > maxValue)
	        {
                maxValue = nums[i];
                maxIndex = i;
	        }
        }
        TreeNode* root = new TreeNode(maxValue);
        if (maxIndex - start >= 1) //左边至少有一个节点
        {
            root->left = count(nums, start, maxIndex);
        }
        if (end - maxIndex > 1) //右边至少有一个节点
        {
            root->right = count(nums, maxIndex + 1, end);
        }
        return root;
    }
};

//int main()
//{
//    vector<int> nums = { 3,2,1,6,0,5 };
//    Solution solution;
//    solution.constructMaximumBinaryTree(nums);
//    return 0;
//}