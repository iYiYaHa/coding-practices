/*
 * @lc app=leetcode id=687 lang=cpp
 *
 * [687] Longest Univalue Path
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
class Solution {
private:
  int longestThroughRoot(TreeNode *root, int &maxVal) {
    if (root == nullptr)
      return 0;
    int leftSub = longestThroughRoot(root->left, maxVal);
    int rightSub = longestThroughRoot(root->right, maxVal);
    int leftLen = root->left && root->left->val == root->val ? leftSub+1 : 0;
    int rightLen = root->right && root->right->val == root->val ? rightSub+1 : 0;
    maxVal = max(maxVal, leftLen + rightLen);
    return max(leftLen, rightLen);
  }

public:
  int longestUnivaluePath(TreeNode *root) {
    int maxVal = 0;
    longestThroughRoot(root, maxVal);
    return maxVal;
  }
};
