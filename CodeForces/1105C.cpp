#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
    const long MODNUM = 1000000007LL;

public:
    int getNumOfArrays(int n, int l, int r, int k = 3)
    {
        vector<vector<int>> dp(n + 1, vector<int>(k, 0));
        if (n < 1)
            return 0;

        for (int j = 0; j < k; ++j)
        {
            dp[1][j] = floor((r - j)*1.0 / k) - ceil((l - j)*1.0/ k) + 1;
        }

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < k; ++j)
            {
                for (int l = 0; l < k; ++l)
                {
                    int otherInd = ((j - l) % k + k) % k;
                    dp[i][j] = (dp[i][j] + (1LL * dp[i - 1][l] * dp[1][otherInd]) % MODNUM) % MODNUM; // Note that % with a negative number.
                }
            }
        }
        return dp[n][0];
    }
};

int main()
{
    Solution s;
    int n, l, r;
    while (cin >> n >> l >> r)
    {
        int res = s.getNumOfArrays(n, l, r);
        cout << res << endl;
    }
    return 0;
}
