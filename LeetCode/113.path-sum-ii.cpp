/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 *
 * https://leetcode.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (44.41%)
 * Likes:    1420
 * Dislikes: 48
 * Total Accepted:    301.1K
 * Total Submissions: 673.3K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's
 * sum equals the given sum.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given the below binary tree and sum = 22,
 * 
 * 
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \    / \
 * 7    2  5   1
 * 
 * 
 * Return:
 * 
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
 * 
 * 
 */

// @lc code=start
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
public:
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<vector<int>> ans;
        vector<int> path;
        helper(root, sum, path, ans);
        return ans;
    }

private:
    void helper(TreeNode *root, int &sum, vector<int> &path, vector<vector<int>> &ans)
    {
        if (root == nullptr)
            return;
        sum -= root->val;
        path.push_back(root->val);
        if (sum == 0 && root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(path);
        }
        else
        {
            helper(root->left, sum, path, ans);
            helper(root->right, sum, path, ans);
        }
        sum += root->val;
        path.pop_back();
    }
};
// @lc code=end
