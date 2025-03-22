#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

class SolutionA
{
public:
    vector<double> twoSum(int n)
    {
        vector<double> ans;
        vector<vector<int>> dp(n + 1, vector<int>(6 * n + 1, 0));

        for (int j = 1; j <= 6; ++j)
            dp[1][j] = 1;
        for (int i = 2; i <= n; ++i)
        {
            for (int j = i; j <= 6 * i; ++j)
            {
                for (int k = max(i - 1, j - 6); k <= j - 1; ++k)
                {
                    dp[i][j] += dp[i - 1][k];
                }
            }
        }
        int sum = pow(6, n);
        for (int i = n; i <= 6 * n; ++i)
            ans.push_back(dp[n][i] * 1.0 / sum);
        return ans;
    }
};

class SolutionB
{
public:
    vector<double> twoSum(int n)
    {
        vector<double> ans;
        vector<vector<int>> dp(2, vector<int>(6 * n + 1, 0));
        for (int i = 1; i <= 6; ++i)
            dp[1][i] = 1;
        for (int i = 2; i <= n; ++i)
        {
            for (int j = i; j <= 6 * i; ++j)
            {
                dp[i % 2][j] = 0;
                for (int k = max(i - 1, j - 6); k <= j - 1; ++k) // Note that j >=i-1
                    dp[i % 2][j] += dp[(i - 1) % 2][k];
            }
        }
        int sum = pow(6, n);
        for (int i = n; i <= 6 * n; ++i)
            ans.push_back(dp[n % 2][i] * 1.0 / sum);
        return ans;
    }
};

class Solution
{
public:
    vector<double> twoSum(int n)
    {
        vector<double> ans;
        vector<int> dp(6 * n + 1, 0);
        for (int i = 1; i <= 6; ++i)
            dp[i] = 1;
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 6 * i; j >= i; --j)
            {
                dp[j] = 0;
                for (int k = max(i - 1, j - 6); k <= j - 1; ++k)
                    dp[j] += dp[k];
            }
        }
        int sum = pow(6, n);
        for (int i = n; i <= 6 * n; ++i)
            ans.push_back(dp[i] * 1.0 / sum);
        return ans;
    }
};

int main()
{
    Solution s;
    assert(s.twoSum(1) == vector<double>({1.0 / 6, 1.0 / 6, 1.0 / 6, 1.0 / 6, 1.0 / 6, 1.0 / 6}));
    return 0;
}