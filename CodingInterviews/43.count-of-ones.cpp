#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int cnt = 0;
        for (long long i = 1; i <= n; i *= 10)
        {
            long long divider = i * 10;
            cnt += (n / divider) * i + min(max(n % divider - i + 1, 0LL), i);
        }
        return cnt;
    }
};

int main()
{
    Solution s;
    assert(s.NumberOf1Between1AndN_Solution(100) == 21);
    assert(s.NumberOf1Between1AndN_Solution(1275) == 734);
    assert(s.NumberOf1Between1AndN_Solution(21345) == 18821);
}