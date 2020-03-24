#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

class Solution
{

public:
    Solution()
    {
    }
    double getProb(int a, int b)
    {
        if (a == 0)
            return 0;
        if (b == 0)
            return 1;
        vector<vector<double>> dp(a + 1, vector<double>(b + 1, 0));
        for (int i = 1; i <= a; ++i)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= b; ++i)
        {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= a; ++i)
        {
            for (int j = 1; j <= b; ++j)
            {
                double n = i, m = j;
                dp[i][j] = n / (n + m);
                if (j >= 2)
                    dp[i][j] += (m / (n + m)) * ((m - 1) / (n + m - 1)) * ((n) / (n + m - 2)) * dp[i - 1][j - 2];
                if (j >= 3)
                    dp[i][j] += (m / (n + m)) * ((m - 1) / (n + m - 1)) * ((m - 2) / (n + m - 2)) * dp[i][j - 3];
            }
        }
        return dp[a][b];
    }
};

int main()
{
    Solution s;
    int a, b;
    while (cin >> a >> b)
    {
        printf("%.9lf\n", s.getProb(a, b));
    }
    return 0;
}