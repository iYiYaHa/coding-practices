/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle/description/
 *
 * algorithms
 * Medium (38.46%)
 * Total Accepted:    171.2K
 * Total Submissions: 445K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step
 * you may move to adjacent numbers on the row below.
 *
 * For example, given the following triangle
 *
 *
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 *
 *
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 *
 * Note:
 *
 * Bonus point if you are able to do this using only O(n) extra space, where n
 * is the total number of rows in the triangle.
 *
 */
#include<vector>
#include<algorithm>
class Solution
{
public:
	int minimumTotal(std::vector<std::vector<int>> &triangle)
	{
		if (triangle.size() == 0 || triangle[0].size() == 0)
			return 0;
		std::vector<std::vector<int>> dp(2, std::vector<int>(triangle.back().size(), 0));
		dp[(triangle.size() - 1) % 2] = triangle.back();
		for (int i = triangle.size() - 2; i >= 0; --i)
		{
			for (int j = 0; j <= i; ++j)
			{
				dp[i % 2][j] = std::min(dp[(i + 1) % 2][j], dp[(i + 1) % 2][j + 1]) + triangle[i][j];
			}
		}
		return dp[0][0];
	}
};
