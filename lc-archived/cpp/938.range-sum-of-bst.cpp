/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
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
public:
  int rangeSumBST(TreeNode *root, int L, int R) {
    if (root == nullptr)
      return 0;
    int leftRangeSum = rangeSumBST(root->left, L, R);
    int rightRangeSum = rangeSumBST(root->right, L, R);
    int curVal = root->val >= L && root->val <= R ? root->val : 0;
    return leftRangeSum + rightRangeSum + curVal;
  }
};

class SolutionB {
public:
  int rangeSumBST(TreeNode *root, int L, int R) {
    if (root == nullptr)
      return 0;
    return rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R) +
           (root->val >= L && root->val <= R ? root->val : 0);
  }
};
