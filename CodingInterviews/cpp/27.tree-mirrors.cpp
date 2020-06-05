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
    void Mirror(TreeNode *pRoot)
    {
        if (pRoot == nullptr)
            return;

        Mirror(pRoot->left);
        Mirror(pRoot->right);

        TreeNode *tmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tmp;
        return;
    }
};

// Non-recursive solution.
class SolutionB
{
public:
    void Mirror(TreeNode *pRoot)
    {
        if (pRoot == nullptr)
            return;
        queue<TreeNode *> q;
        q.push(pRoot);
        while (!q.empty())
        {
            TreeNode *top = q.front();
            q.pop();

            // Mirror children
            TreeNode *tmp = top->left;
            top->left = top->right;
            top->right = tmp;

            // Process children
            if (top->left != nullptr)
                q.push(top->left);
            if (top->right != nullptr)
                q.push(top->right);
        }
    }
}