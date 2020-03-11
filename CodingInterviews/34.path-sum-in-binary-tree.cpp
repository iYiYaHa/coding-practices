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
    vector<vector<int>> FindPath(TreeNode *root, int expectNumber)
    {
        vector<vector<int>> ans;
        vector<int> path;
        findAllPaths(ans, root, 0, expectNumber, path);
        sort(ans.begin(), ans.end(), [](const vector<int> &a, const vector<int> &b) { return a.size() >= b.size(); });
        return ans;
    }

private:
    void findAllPaths(vector<vector<int>> &ans, TreeNode *root, int curSum, int target, vector<int> &path)
    {
        if (root == nullptr)
            return;
        path.push_back(root->val);
        curSum += root->val;
        if (curSum == target && root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(path);
        }
        else
        {
            findAllPaths(ans, root->left, curSum, target, path);
            findAllPaths(ans, root->right, curSum, target, path);
        }

        path.pop_back();
    }
};

// I prefer the above solution.

class SolutionB
{
public:
    vector<vector<int>> FindPath(TreeNode *root, int expectNumber)
    {
        findAllPaths(root, expectNumber);
        sort(ans.begin(), ans.end(), [](const vector<int> &a, const vector<int> &b) { return a.size() >= b.size(); });
        return ans;
    }

private:
    vector<vector<int>> ans;
    vector<int> path;
    void findAllPaths(TreeNode *root, int target)
    {
        if (root == nullptr)
            return;
        path.push_back(root->val);
        target -= root->val;
        if (target == 0 && root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(path);
        }
        else
        {
            findAllPaths(root->left, target);
            findAllPaths(root->right, target);
        }

        path.pop_back();
    }
};