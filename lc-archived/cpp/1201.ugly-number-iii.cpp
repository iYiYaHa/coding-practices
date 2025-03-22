/*
 * @lc app=leetcode id=1201 lang=cpp
 *
 * [1201] Ugly Number III
 *
 * https://leetcode.com/problems/ugly-number-iii/description/
 *
 * algorithms
 * Medium (25.01%)
 * Likes:    143
 * Dislikes: 168
 * Total Accepted:    6.6K
 * Total Submissions: 26.3K
 * Testcase Example:  '3\n2\n3\n5'
 *
 * Write a program to find the n-th ugly number.
 * 
 * Ugly numbers are positive integers which are divisible by a or b or c.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3, a = 2, b = 3, c = 5
 * Output: 4
 * Explanation: The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10... The 3rd is 4.
 * 
 * Example 2:
 * 
 * 
 * Input: n = 4, a = 2, b = 3, c = 4
 * Output: 6
 * Explanation: The ugly numbers are 2, 3, 4, 6, 8, 9, 10, 12... The 4th is
 * 6.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 5, a = 2, b = 11, c = 13
 * Output: 10
 * Explanation: The ugly numbers are 2, 4, 6, 8, 10, 11, 12, 13... The 5th is
 * 10.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: n = 1000000000, a = 2, b = 217983653, c = 336916467
 * Output: 1999999984
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n, a, b, c <= 10^9
 * 1 <= a * b * c <= 10^18
 * It's guaranteed that the result will be in range [1, 2 * 10^9]
 * 
 * 
 */

// @lc code=start

// Time Complexity: O(n)
// Time Limit Exceeded
class SolutionA
{
public:
    int nthUglyNumber(int n, int a, int b, int c)
    {
        int resA = a;
        int resB = b;
        int resC = c;
        int ans = a;
        for (int i = 0; i < n; ++i)
        {
            ans = std::min(resA, stdt::min(resB, resC));
            if (ans == resA)
                resA += a;
            if (ans == resB)
                resB += b;
            if (ans == resC)
                resC += c;
        }
        return ans;
    }
};

class Solution
{
public:
    int nthUglyNumber(int n, int a, int b, int c)
    {
        long long left = 1, right = 2 * 10e9;
        while (left < right)
        {
            long long mid = left + (right - left) / 2;
            long long cnt = countUglyNum(n, a, b, c);
            if (cnt < n)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }

private:
    long long gcd(long long a, long long b)
    {
        return b ? gcd(b,a%b) : a;
    }

    long long lcm(long long a, long long b)
    {
        return a / gcd(a, b) * b ;
    }

    int countUglyNum(int n, int a, int b, int c)
    {
        long long cntA = n / a;
        long long cntB = n / b;
        long long cntC = n / c;
        long long cntAB = n / lcm(a, b);
        long long cntBC = n / lcm(b, c);
        long long cntAC = n / lcm(a, c);
        long long cntABC = n / lcm(a, lcm(b, c));
        return cntA + cntB + cntC - cntAB - cntBC - cntAC + cntABC;
    }
};

// @lc code=end
