class Solution
{
public:
    bool IsBalanced_Solution(TreeNode *pRoot)
    {
        int depth = 0;
        return helper(pRoot, depth);
    }

private:
    bool helper(TreeNode *pRoot, int &depth)
    {
        if (pRoot == nullptr)
        {
            depth = 0;
            return true;
        }
        int left = 0, right = 0;
        bool isLeftBalanced = helper(pRoot->left, left);
        bool isRightBalanced = helper(pRoot->right, right);

        depth = 1 + std::max(left, right);
        return isLeftBalanced && isRightBalanced &&
               abs(left - right) <= 1;
    }
};
