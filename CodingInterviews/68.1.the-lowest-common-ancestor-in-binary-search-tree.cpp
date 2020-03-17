class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr || p == nullptr || q == nullptr)
            return nullptr;

        int rootVal = root->val, pVal = p->val, qVal = q->val;
        if (rootVal < pVal && rootVal < qVal)
            return lowestCommonAncestor(root->right, p, q);
        else if (rootVal > pVal && rootVal > qVal)
            return lowestCommonAncestor(root->left, p, q);
        else
            return root;
    }
};