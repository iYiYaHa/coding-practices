#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

class SolutionA
{
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int cnt = 0;
        for (long long i = 1; i <= n; i *= 10)
        {
            long long divider = i * 10;
            cnt += (n / divider) * i + min(max((n % divider - i + 1), 0LL), i);
        }
        return cnt;
    }
};

//ref: https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/solution/javadi-gui-by-xujunyi/
class SolutionB
{
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if (n <= 0)
            return 0;
        string numStr = std::to_string(n);
        int len = numStr.length();
        int high = numStr[0] - '0';
        int powVal = pow(10, len - 1);
        int last = n % powVal;
        if (high == 1)
        {
            return NumberOf1Between1AndN_Solution(last) + last + 1 + NumberOf1Between1AndN_Solution(powVal - 1);
        }
        else
        {
            return high * NumberOf1Between1AndN_Solution(powVal - 1) + NumberOf1Between1AndN_Solution(last) + powVal;
        }
    }
};

//ref: https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/solution/java100fu-si-lu-shuo-ming-by-xyx1273930793-2/
class SolutionC
{
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if (n <= 0)
            return 0;
        int cnt = 0;
        int i = 1;
        while (i <= n)
        {
            int high = n / (i * 10);
            int cur = (n / i) % 10;
            int low = n % i;
            if (cur == 0)
                cnt += high * i;
            else if (cur == 1)
                cnt += high * i + low + 1;
            else
                cnt += (high + 1) * i;
            i *= 10;
        }
        return cnt;
    }
};

//ref: https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/solution/xiang-jie-gui-lu-yong-shi-0ms-by-sircarol/
// Like an optimization on the above solution.
class Solution
{
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if (n <= 0)
            return 0;
        int cnt = 0;
        for (int i = 1; i <= n; i *= 10)
        {
            int a = n / i;
            int b = n % i;

            cnt += ((a + 8) / 10) * i + (a % 10 == 1 ? b + 1 : 0);
        }
        return cnt;
    }
};

int main()
{
    Solution s;
    assert(s.NumberOf1Between1AndN_Solution(9) == 1);
    assert(s.NumberOf1Between1AndN_Solution(13) == 6);
    assert(s.NumberOf1Between1AndN_Solution(100) == 21);
    assert(s.NumberOf1Between1AndN_Solution(1275) == 734);
    assert(s.NumberOf1Between1AndN_Solution(21345) == 18821);
}