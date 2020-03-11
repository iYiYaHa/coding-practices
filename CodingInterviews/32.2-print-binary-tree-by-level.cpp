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
    vector<vector<int>> Print(TreeNode *pRoot)
    {
        if (pRoot == nullptr)
            return vector<vector<int>>();
        vector<vector<int>> ans;
        vector<int> curLevel;
        queue<TreeNode *> q;
        q.push(pRoot);
        int numCurLevel = 1;
        int numNextLevel = 0;
        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();
            curLevel.push_back(front->val);
            --numCurLevel;
            if (front->left != nullptr)
            {
                ++numNextLevel;
                q.push(front->left);
            }
            if (front->right != nullptr)
            {
                ++numNextLevel;
                q.push(front->right);
            }
            if (numCurLevel == 0)
            {
                ans.push_back(curLevel);
                curLevel.clear();
                numCurLevel = numNextLevel;
                numNextLevel = 0;
            }
        }
        return ans;
    }
};