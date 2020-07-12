/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 *
 * https://leetcode.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (35.74%)
 * Total Accepted:    99.5K
 * Total Submissions: 277.7K
 * Testcase Example:  '10'
 *
 * Write a program to find the n-th ugly number.
 * 
 * Ugly numbers are positive numbers whose prime factors only include 2, 3,
 * 5. 
 * 
 * Example:
 * 
 * 
 * Input: n = 10
 * Output: 12
 * Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
 * ugly numbers.
 * 
 * Note:  
 * 
 * 
 * 1 is typically treated as an ugly number.
 * n does not exceed 1690.
 * 
 */
class Solution
{
  public:
    int nthUglyNumber(int n)
    {
        int indexTwo = 0, indexThree = 0, indexFive = 0;
        std::vector<int> table;
        table.push_back(1);
        int resTwo = table[indexTwo] * 2;
        int resThree = table[indexThree] * 3;
        int resFive = table[indexFive] * 5;
        for (int i = 1; i < n; ++i)
        {
            int next = std::min(resTwo, std::min(resThree, resFive));
            table.push_back(next);
            if (next == resTwo)
                resTwo = table[++indexTwo] * 2;
            if (next == resThree)
                resThree = table[++indexThree] * 3;
            if (next == resFive)
                resFive = table[++indexFive] * 5;
        }
        return table.back();
    }
};
