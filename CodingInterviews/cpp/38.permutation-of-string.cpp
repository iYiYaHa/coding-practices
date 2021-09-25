#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> Permutation(string str)
    {
        vector<string> ans;
        if (str.length() == 0)
            return ans;
        helper(ans, str, 0);
        sort(ans.begin(),ans.end());
        return ans;
    }

private:
    void helper(vector<string> &ans, string &str, int beg)
    {
        if (beg == str.size())
            ans.push_back(str);
        else
        {
            for (int i = beg; i < str.size(); ++i)
            {
                if (i!=beg && str[i] == str[beg]) // for aa, aaa,
                    continue;
                char tmp = str[i];
                str[i] = str[beg];
                str[beg] = tmp;
                helper(ans, str, beg + 1);
                tmp = str[i];
                str[i] = str[beg];
                str[beg] = tmp;
            }
        }
    }
};


int main()
{
    Solution s;
    string str = "abc";
    auto res = s.Permutation(str);
    for (string p : res)
    {
        cout << p << endl;
    }
    return 0;
}