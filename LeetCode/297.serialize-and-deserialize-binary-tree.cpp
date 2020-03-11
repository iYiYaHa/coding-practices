/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 *
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (45.10%)
 * Likes:    2455
 * Dislikes: 121
 * Total Accepted:    272.5K
 * Total Submissions: 602.9K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 * 
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.
 * 
 * Example: 
 * 
 * 
 * You may serialize the following tree:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠    / \
 * ⁠   4   5
 * 
 * as "[1,2,3,null,null,4,5]"
 * 
 * 
 * Clarification: The above format is the same as how LeetCode serializes a
 * binary tree. You do not necessarily need to follow this format, so please be
 * creative and come up with different approaches yourself.
 * 
 * Note: Do not use class member/global/static variables to store states. Your
 * serialize and deserialize algorithms should be stateless.
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CodecA
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == nullptr)
            return "#,";
        string left = serialize(root->left);
        string right = serialize(root->right);
        string rootStr = std::to_string(root->val) + ",";
        return rootStr + left + right;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data == "")
            return nullptr;
        int ind = 0;
        return deserializeHelper(data, ind);
    }

private:
    TreeNode *deserializeHelper(const string &str, int &ind)
    {
        if (str.size() <= 0 || ind >= str.size())
            return nullptr;
        if (str[ind] == '#')
        {
            ind += 2;
            return nullptr;
        }
        int rootVal = 0;
        int i = ind;
        for (; str[i] != ','; ++i)
            ;
        istringstream is(str.substr(ind, i - ind + 1));
        is >> rootVal;
        ind = i + 1;

        TreeNode *root = new TreeNode(rootVal);
        root->left = deserializeHelper(str, ind);
        root->right = deserializeHelper(str, ind);
        return root;
    }
};

// Using istringstream to avoid problems when processing strings.
class CodecB
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        ostringstream os;
        serializeHelper(root, os);
        return os.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        istringstream is(data);
        return deserializeHelper(is);
    }

private:
    void serializeHelper(const TreeNode *root, ostringstream &os)
    {
        if (root)
        {
            os << root->val << " ";
            serializeHelper(root->left, os);
            serializeHelper(root->right, os);
        }
        else
        {
            os << "# ";
        }
    }

    TreeNode *deserializeHelper(istringstream &is)
    {
        string str = "";
        is>>str;
        if(str == "#"){
            return nullptr;
        }
        TreeNode *root = new TreeNode(stoi(str));
        root->left = deserializeHelper(is);
        root->right = deserializeHelper(is);
        return root;
    }
};

// Using istringstream to avoid problems when processing strings.
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        ostringstream os;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *top = q.front();
            q.pop();
            if(top == nullptr){
                os<<"# ";
            }else{
                os<<top->val<<" ";
                q.push(top->left);
                q.push(top->right);
            }
        }
        return os.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        istringstream is(data);
        queue<TreeNode**> q;
        string str;
        TreeNode *root=nullptr;
        q.push(&root);
        while(is>>str){
            TreeNode **top = q.front();
            q.pop();

            if(str == "#"){
                *top = nullptr;
            }else{
                *top = new TreeNode(stoi(str));
                q.push(&((*top)->left));
                q.push(&((*top)->right));
            }
        }
        return root;
    }
};
    // Your Codec object will be instantiated and called as such:
    // Codec codec;
    // codec.deserialize(codec.serialize(root));
    // @lc code=end
