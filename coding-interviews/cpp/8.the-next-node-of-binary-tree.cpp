class Solution
{
public:
    TreeLinkNode *GetNext(TreeLinkNode *pNode)
    {
        if (pNode == nullptr)
            return nullptr;

        if (pNode->right != nullptr)
        {
            TreeLinkNode *cur = pNode->right;
            while (cur->left != nullptr)
                cur = cur->left;
            return cur;
        }
        else
        {
            TreeLinkNode *parent = pNode->next;
            while (parent != nullptr && parent->left != pNode)
            {
                pNode = parent;
                parent = parent->next;
            }
            return parent;
        }
    }
};