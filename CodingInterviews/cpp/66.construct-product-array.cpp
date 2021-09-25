#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> multiply(const vector<int> &A)
    {
        vector<int> ans(A.size());
        if (A.size() > 0)
        {
            ans[0] = 1;
            for (int i = 1; i < A.size(); ++i)
            {
                ans[i] = ans[i - 1] * A[i - 1];
            }
            int tmp = 1;
            for (int i = A.size() - 2; i >= 0; --i)
            {
                tmp *= A[i + 1];
                ans[i] *= tmp;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {};
    nums = {1, 2, 3, 4, 5};
    assert(s.multiply(nums) == vector<int>({120, 60, 40, 30, 24}));
    return 0;
}