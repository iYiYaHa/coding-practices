/*
 * @lc app=leetcode id=375 lang=cpp
 *
 * [375] Guess Number Higher or Lower II
 *
 * https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/
 *
 * algorithms
 * Medium (37.30%)
 * Total Accepted:    41.6K
 * Total Submissions: 111.5K
 * Testcase Example:  '1'
 *
 * We are playing the Guess Game. The game is as follows:
 *
 * I pick a number from 1 to n. You have to guess which number I picked.
 *
 * Every time you guess wrong, I'll tell you whether the number I picked is
 * higher or lower.
 *
 * However, when you guess a particular number x, and you guess wrong, you pay
 * $x. You win the game when you guess the number I picked.
 *
 * Example:
 *
 *
 * n = 10, I pick 8.
 *
 * First round:  You guess 5, I tell you that it's higher. You pay $5.
 * Second round: You guess 7, I tell you that it's higher. You pay $7.
 * Third round:  You guess 9, I tell you that it's lower. You pay $9.
 *
 * Game over. 8 is the number I picked.
 *
 * You end up paying $5 + $7 + $9 = $21.
 *
 *
 * Given a particular n ¡Ý 1, find out how much money you need to have to
 * guarantee a win.
 */

 //ref: https://www.hackerearth.com/blog/artificial-intelligence/minimax-algorithm-alpha-beta-pruning/
#include<vector>
#include<numeric>
#include<algorithm>
class Solution {
	// Dynamic programming based Minimax algorithm.
	//
	// Considering the worst case, each time we guess a number, the result is wrong unless there is only a number to guess.
	//
	// At the first guess, we pick up a number k between 1 and n, which is not the target and causes a cost of k.
	//
	// Then we have to guess between 1 and k-1 or k+1 and n, depending the result of last guess which is lesser or greater.
	// To find out the least money to guarantee a win, we must considered the worst case which is of the most cost between 
	// the left part and the right part spilted by k
	//
	// Recursivly consider each part individually, this will be a top-down process forming a tree whose nodes represents a
	// possible range with overlapping subproblems. This is where DP works.
	//
	// dp[i][j] = min(max(k + dp[i][k-1],k + dp[k+1][j]) for all k between i and j)

	// Since ..., we can start k from (i+j)/2.
public:
	int getMoneyAmount(int n) {
		std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));
		for (int i = n; i >= 1; --i) {
			for (int j = i + 1; j <= n; ++j) {
				dp[i][j] = std::numeric_limits<int>::max();
				for (int k = (i + j) / 2; k <= j; ++k) {
					int left = k - 1 >= 0 ? dp[i][k - 1] : 0;
					int right = k + 1 <= n ? dp[k + 1][j] : 0;
					dp[i][j] = std::min(dp[i][j], k + std::max(left, right));
				}
			}
		}
		return dp[1][n];
	}
};

