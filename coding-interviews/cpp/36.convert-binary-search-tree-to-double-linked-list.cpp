/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

class SolutionA
{
public:
    TreeNode *Convert(TreeNode *pRootOfTree)
    {
        TreeNode *tail = nullptr;
        return convertCore(pRootOfTree, tail);
    }

private:
    TreeNode *convertCore(TreeNode *root, TreeNode *&tail)
    {
        if (root == nullptr)
        {
            tail = nullptr;
            return nullptr;
        }

        TreeNode *head = nullptr, *leftTail = nullptr, *rightTail = nullptr;
        TreeNode *leftHead = convertCore(root->left, leftTail);
        TreeNode *rightHead = convertCore(root->right, rightTail);

        root->right = rightHead;
        root->left = leftTail;

        if (leftTail != nullptr)
            leftTail->right = root;
        if (rightHead != nullptr)
            rightHead->left = root;
        head = leftHead ? leftHead : root;
        tail = rightTail ? rightTail : root;
        return head;
    }
};

class Solution
{
public:
    TreeNode *Convert(TreeNode *pRootOfTree)
    {
        TreeNode *pre = nullptr;
        convertCore(pRootOfTree, pre);
        while (pRootOfTree !=nullptr && pRootOfTree->left != nullptr)
            pRootOfTree = pRootOfTree->left;
        return pRootOfTree;
    }
private:
    void convertCore(TreeNode *root, TreeNode *&pre){
        if(root == nullptr){
            return;
        }
        convertCore(root->left, pre);
        root->left = pre;
        if(pre)pre->right = root;
        pre = root;
        convertCore(root->right, pre);
    }
};