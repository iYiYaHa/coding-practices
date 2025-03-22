#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};

class Solution
{
public:
    char *Serialize(TreeNode *root)
    {
        if (root == nullptr)
        {
            char *res = new char[2];
            *res = '#';
            *(res+1)='\0';
            return res;
        }
        char *left = Serialize(root->left);
        char *right = Serialize(root->right);

        // Compute the length needed.
        int leftLen = strlen(left);
        int leftRight = strlen(right);
        int digits = countDigits(root->val);
        int len = leftLen + leftRight + digits + 1 + 1;

        // Create a char array and copy root value inside.
        char *res = new char[len];
        res[digits] = ',';
        for (int cnt = digits - 1, rootVal = root->val; cnt>=0; --cnt, rootVal /= 10)
        {
            res[cnt] = (rootVal % 10) + '0';
        }
        // Copy left tree and right Tree
        strcpy(res + digits + 1, left);
        strcpy(res + digits + 1 + leftLen, right);
        
        res[len] = '\0';
        return res;
    }
    TreeNode *Deserialize(char *&str)
    {
        if (str == nullptr || *str == '\0')
            return nullptr;

        if(*str == '#'){
            ++str;
            return nullptr;
        }

        int num = 0;
        for (; *str != '\0' && *str >= '0' && *str <= '9'; ++str)
        {
            num = num * 10 + (*str - '0');
        }
        if (*str == ',')
            ++str;
            
        TreeNode *root = new TreeNode(num);
        root->left = Deserialize(str);
        root->right = Deserialize(str);
        return root;
    }

private:
    int countDigits(int num)
    {
        int count = 0;
        while (num)
        {
            num /= 10;
            ++count;
        }
        return count;
    }
};

void printTree(TreeNode *root)
{
    if (root == nullptr){
        cout << "#";
        return;
    }
    cout << root->val << ",";
    printTree(root->left);
    printTree(root->right);
}
int main()
{
    Solution s;
    char str[] = "1,2,4,###3,53,##6,##";
    char *tmp = (char*)&str;
    TreeNode *root = s.Deserialize(tmp);
    cout << "----" << endl;
    printTree(root);
    cout << "\n----" << endl;
    cout << s.Serialize(root) << endl;
    return 0;
}