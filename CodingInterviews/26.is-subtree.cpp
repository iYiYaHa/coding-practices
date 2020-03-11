/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution
{
public:
    bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        if (pRoot1 != nullptr && pRoot2 != nullptr)
        {
            return isSameTree(pRoot1, pRoot2) ||
                   HasSubtree(pRoot1->left, pRoot2) ||
                   HasSubtree(pRoot1->right, pRoot2);
        }
        return false;// 按照定义，空树不是任何一个树的子结构。
    }

private:
    bool isSameTree(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        if (pRoot2 == nullptr) // 不一定完全相同，有可能已经匹配完了，即 pRoot2 是 pRoot1 的子结构，但不完全一样。
            return true;
        if (pRoot1 == nullptr)
            return false;
        return pRoot1->val == pRoot2->val &&
               isSameTree(pRoot1->left, pRoot2->left) &&
               isSameTree(pRoot1->right, pRoot2->right);
    }
};