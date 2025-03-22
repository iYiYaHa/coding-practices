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
    TreeNode *KthNode(TreeNode *pRoot, int k)
    {
        return KthNodeHelper(pRoot, k);
    }

private:
    TreeNode *KthNodeHelper(TreeNode *pRoot, int &k)
    {
        if (pRoot == nullptr)
            return nullptr;
        TreeNode *left = KthNodeHelper(pRoot->left, k);

        if (left != nullptr) // If kth node is at the left subtree.
            return left;
        if (k == 1)
            return pRoot;
        --k;

        TreeNode *right = KthNodeHelper(pRoot->right, k);
        return right;
    }
};