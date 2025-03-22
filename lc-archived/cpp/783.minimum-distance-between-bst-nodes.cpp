/*
 * @lc app=leetcode id=783 lang=cpp
 *
 * [783] Minimum Distance Between BST Nodes
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class SolutionA
{
private:
    void getValsInOrder(TreeNode *root, vector<int> &nums)
    {
        if (root == nullptr)
            return;
        getValsInOrder(root->left, nums);
        nums.push_back(root->val);
        getValsInOrder(root->right, nums);
    }

public:
    int minDiffInBST(TreeNode *root)
    {
        vector<int> nums;
        getValsInOrder(root, nums);
        int diff = std::numeric_limits<int>::max();
        for (int i = 1; i < nums.size(); ++i)
        {
            diff = min(diff, nums[i] - nums[i - 1]);
        }
        return diff;
    }
};

class Solution
{
private:
    int helper(TreeNode *root, TreeNode *&pre)
    {
        if (root == nullptr)
            return numeric_limits<int>::max();
        int leftMin = helper(root->left, pre);
        int midDiff = pre != nullptr ? root->val - pre->val : numeric_limits<int>::max();
        pre = root;
        int rightMin = helper(root->right, pre);
        return min(leftMin, min(midDiff, rightMin));
    }

public:
    int minDiffInBST(TreeNode *root)
    {
        TreeNode *pre = nullptr;
        return helper(root, pre);
    }
};
