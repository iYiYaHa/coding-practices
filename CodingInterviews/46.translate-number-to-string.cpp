#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SolutionA
{
public:
    int translateNum(int num)
    {
        if (num < 0)
            return 0;
        string numStr = std::to_string(num);
        vector<int> dp(numStr.length());
        dp[numStr.size() - 1] = 1;
        for (int i = numStr.size() - 2; i >= 0; --i)
        {
            dp[i] = dp[i + 1];
            int num = (numStr[i] - '0') * 10 + (numStr[i + 1] - '0');
            if (num >= 10 && num <= 25)
                dp[i] += i < numStr.size() - 2 ? dp[i + 2] : 1;
        }
        return dp[0];
    }
};

class Solution
{
public:
    int translateNum(int num)
    {
        if (num < 0)
            return 0;
        if (num < 10)//num == 0 for the situation num is zero or num is the result of two-digit number divided by 100.
            return 1;
        int lastTwo = num % 100;
        if (lastTwo <= 25 && lastTwo >= 10)
            return translateNum(num / 100) + translateNum(num / 10);
        else
            return translateNum(num / 10);
    }
};
int main()
{
    Solution s;
    assert(s.translateNum(12258) == 5);
    assert(s.translateNum(25) == 2);
    assert(s.translateNum(2512937) == 4);
    return 0;
}
