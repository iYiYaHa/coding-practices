#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int getMaxValue(const vector<vector<int>> &values)
    {
        int n = values.size();
        if (n <= 0)
            return 0;
        int m = values.size();
        if (m <= 0)
            return 0;
        vector<int> dp(m, 0);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                dp[j] = max(i > 0 ? dp[j] : 0, j > 0 ? dp[j - 1] : 0) + values[i][j];
            }
        }
        return dp.back();
    }
};

int main()
{
    Solution s;
    assert(s.getMaxValue({{1, 10, 3, 8}, {12, 2, 9, 6}, {5, 7, 4, 11}, {3, 7, 16, 5}}) == 53);
}