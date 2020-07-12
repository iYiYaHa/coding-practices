/*
 * @lc app=leetcode id=894 lang=cpp
 *
 * [894] All Possible Full Binary Trees
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
    // Note that this code will cause memory leak
    // since each root node may be taken as children nodes for several parent nodes.
    // Clone before assignment will solve this problem.
    // And caching results will speed up.
public:
    vector<TreeNode *> allPossibleFBT(int N)
    {
        vector<TreeNode *> res;
        if (N % 2 == 0)
            return res;
        if (N == 1)
        {
            res.push_back(new TreeNode(0));
            return res;
        }
        for (int num_left = 1; num_left < N; num_left += 2)
        {
            for (TreeNode *leftSubTree : allPossibleFBT(num_left))
            {
                for (TreeNode *rightSubTree : allPossibleFBT(N - 1 - num_left))
                {
                    TreeNode *node = new TreeNode(0);
                    node->left = leftSubTree;
                    node->right = rightSubTree;
                    res.push_back(node);
                }
            }
        }
        return res;
    }
};
