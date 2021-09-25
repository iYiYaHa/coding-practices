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

        stack<TreeNode *> s[2];
        vector<vector<int>> ans;
        vector<int> curLevel;
        int cur = 0;
        s[cur].push(pRoot);
        while (!s[0].empty() || !s[1].empty())
        {
            TreeNode *top = s[cur].top();
            s[cur].pop();
            curLevel.push_back(top->val);

            if (cur == 0)
            {
                if (top->left != nullptr)
                    s[1 - cur].push(top->left);
                if (top->right != nullptr)
                    s[1 - cur].push(top->right);
            }
            else
            {
                if (top->right != nullptr)
                    s[1 - cur].push(top->right);
                if (top->left != nullptr)
                    s[1 - cur].push(top->left);
            }

            if(s[cur].empty()){
                ans.push_back(curLevel);
                curLevel.clear();
                cur = 1-cur;
            }
        }
        return ans;
    }
};