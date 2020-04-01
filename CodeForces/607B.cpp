#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>

using namespace std;

class Solution
{

public:
    int func(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, n));
        for (int i = 0; i < n; ++i)
            dp[i][i] = 1;
        for (int i = 0; i < n - 1; ++i)
        {
            if (nums[i] == nums[i + 1])
                dp[i][i + 1] = 1;
            else
                dp[i][i + 1] = 2;
        }

        for (int len = 3; len <= n; ++len)
        {
            for (int i = 0; i <= n - len; ++i)
            {
                int j = i + len - 1;

                // Logic One
                // if (nums[i] == nums[j])
                //     dp[i][j] = dp[i + 1][j - 1];
                // for (int k = i; k < j; ++k)
                //     dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);

                // Logic Two
                for (int k = i; k <= j; ++k)
                {
                    if (nums[i] == nums[k])
                    {
                        int left = (k == i + 1 || k == i)? 1 : (dp[i + 1][k - 1]);
                        int right = (k + 1) <= j ? dp[k + 1][j] : 0;
                        dp[i][j] = min(dp[i][j], left + right);
                    }
                }
            }
        }
        return dp[0][n - 1];
    }

private:
};

int main()
{
    Solution s;
    int size;
    int num;
    while (cin >> size)
    {
        vector<int> nums;
        for (int i = 1; i <= size; ++i)
        {
            cin >> num;
            nums.push_back(num);
        }
        cout << s.func(nums) << endl;
    }
}