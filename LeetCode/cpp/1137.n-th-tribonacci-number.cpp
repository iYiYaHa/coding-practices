/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */
//ref:https://leetcode.com/problems/n-th-tribonacci-number/discuss/347604/C%2B%2BO(k3log(n))-Solution-(k3)-Matrix-Exponentiation
// class Solution//(TLE)
// {
// public:
//     int tribonacci(int n)
//     {
//         if (n == 0)
//             return 0;
//         if (n == 1 || n == 2)
//             return 1;
//         return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
//     }
// };

class SolutionA
{
public:
    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        int a = 0, b = 1, c = 1;
        for (int i = 3; i <= n; ++i)
        {
            int tmp = a + b + c;
            a = b;
            b = c;
            c = tmp;
        }
        return c;
    }
};
class Solution
{
public:
    int tribonacci(int n)
    {
        vector<int> dp{0, 1, 1};
        for (int i = 3; i <= n; ++i)
        {
            dp[i % 3] += dp[(i-1) % 3] + dp[(i-2) % 3];
        }
        return dp[n % 3];
    }
};
