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
	vector<int> PrintFromTopToBottom(TreeNode *root)
	{
		if (root == nullptr)
			return vector<int>();
		vector<int> ans;
		queue<TreeNode *> q;
		q.push(root);
		while (!q.empty())
		{
			TreeNode *front = q.front();
			q.pop();
			ans.push_back(front->val);
			if (front->left != nullptr)
				q.push(front->left);
			if (front->right != nullptr)
				q.push(front->right);
		}
		return ans;
	}
};