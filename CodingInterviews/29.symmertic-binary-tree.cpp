/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution
{
public:
    bool isSymmetrical(TreeNode *pRoot)
    {
        if (pRoot == nullptr)
            return true;
        return isSymmetrical(pRoot->left, pRoot->right);
    }

private:
    bool isSymmetrical(TreeNode *pRootA, TreeNode *pRootB)
    {
        if (pRootA == nullptr && pRootB == nullptr)
            return true;
        if (pRootA == nullptr || pRootB == nullptr)
            return false;
        if (pRootA->val == pRootB->val)
        {
            return isSymmetrical(pRootA->left, pRootB->right) && isSymmetrical(pRootA->right, pRootB->left);
        }
        return false;
    }
};