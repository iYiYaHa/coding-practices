/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (35.13%)
 * Total Accepted:    132.3K
 * Total Submissions: 376.6K
 * Testcase Example:  '3'
 *
 * Given an integer n, generate all structurally unique BST's (binary search
 * trees) that store values 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * Explanation:
 * The above output corresponds to the 5 unique BST's shown below:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 * 
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
class Solution
{
    using MemoType = vector<vector<vector<TreeNode *>>>;

  public:
    vector<TreeNode *> generateTrees(int n)
    {
        if (n <= 0)
            return vector<TreeNode *>();
        MemoType memo(n + 1, vector<vector<TreeNode *>>(n + 1));
        return helper(memo, 1, n);
    }

  private:
    vector<TreeNode *> helper(MemoType &memo, int left, int right)
    {
        if (left > right)
            return vector<TreeNode *>{nullptr};
        if (memo[left][right].size() != 0)
            return memo[left][right];
        vector<TreeNode *> ans;
        for (int i = left; i <= right; ++i)
        {
            vector<TreeNode *> leftNodes = helper(memo, left, i - 1);
            vector<TreeNode *> rightNodes = helper(memo, i + 1, right);
            for (TreeNode *leftNode : leftNodes)
            {
                for (TreeNode *rightNode : rightNodes)
                {
                    TreeNode *node = new TreeNode(i);
                    node->left = leftNode;
                    node->right = rightNode;
                    memo[left][right].push_back(node);
                }
            }
        }
        return memo[left][right];
    }
};
