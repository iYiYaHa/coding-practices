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
 * Given a particular n �� 1, find out how much money you need to have to
 * guarantee a win.
 */

//ref: https://www.hackerearth.com/blog/artificial-intelligence/minimax-algorithm-alpha-beta-pruning/
//ref: https://leetcode.com/problems/guess-number-higher-or-lower-ii/discuss/84775/3ms-java-dp-solution/89409
#include <vector>
#include <numeric>
#include <algorithm>

class SolutionA
{
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
	//
	// -----------------------------------------------------------------------------------------------------------------------------
	// "By observing the monotonicity of the left and right parts as well as the fact that dp[i][i+k] <= dp[j][j+k] if i <= j.,
	// we can start k from (i+j)/2.
	// (Why choose one index left to the middle? The goal of this part should be ensure that at the beginning, the length of left
	// part is larger than or equal to the right part, then setting the starting index as the middle (start + end) / 2 should be enough.)"
	//
	// when k = mid-1, dp[i][mid-2] < dp[mid][j],dp[i][j] = mid-1+dp[mid][j]
	// And for all k<mid-1, dp[i][k-1] < dp[k+1][k-1-i+k+1]=dp[k+1][2k-i]<dp[k+1][j], dp[i][j] = k + dp[k+1][j]. k+dp[k+1][j]

	// So searching all children in the game tree of parent node i...j by spliting the whole range with all k < mid=(i+j)/2, the minimized
	// dp[i][j] so far equals (mid-1)+dp[mid][j].
	// when k = mid, dp[i][mid-1] < dp[mid+1][j](mid-1-i <= j-mid-1). Adding mid-1 into both sides, we have
	// mid-1 + dp[i][mid-1] < mid-1+dp[mid+1][j]<mid-1+dp[mid][j](dp[i][j](Obtained with k = mid-1)).
	// mid-1+dp[mid+1][j]

  public:
	int getMoneyAmount(int n)
	{
		std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));
		for (int i = n; i >= 1; --i)
		{
			for (int j = i + 1; j <= n; ++j)
			{
				dp[i][j] = std::numeric_limits<int>::max();
				for (int k = (i + j) / 2; k <= j; ++k)
				{
					int left = k - 1 >= 0 ? dp[i][k - 1] : 0;
					int right = k + 1 <= n ? dp[k + 1][j] : 0;
					dp[i][j] = std::min(dp[i][j], k + std::max(left, right));
				}
			}
		}
		return dp[1][n];
	}
};

//ref: https://artofproblemsolving.com/community/c296841h1273742
class SolutionB
{
	// -----------------------------------------------------------------------------------------------------------------------------
	// Which seems unclear to me is that in zkw's solution(3rd ref.), we have a k_0 between i and j which satisfies that i<=k<=k_0 dp[i][k-1]<dp[k+1][j]
	// and k_0<k<=j dp[i][k-1]>dp[k+1][j]. It worth noting that k_0 may equals j which causes no accessible k > k_0 staisfying k_0<k<=j dp[i][k-1]>dp[k+1][j].
	// And to prove dp[i][k-1]>dp[k+1][j] holds for all k_0<k<=j, for k_0+1, dp[i][k_0]>dp[k_0+2][j]. Then for k_0+2, dp[i][k_0+1]>dp[i][k_0]>dp[k_0+2][j]>dp[k_0+3][j].
	// That is, as k increasing between i and j, the relationship between dp[i][k-1] and dp[k+1][j] trends like "< < < < > > > >" or "< < < < < < < <".
	// So for all k that i<=k<=k_0, max(dp[i][k-1]),dp[k+1][j]) = dp[i][k-1], for all k that k_0<k<=j, max(dp[i][k-1]),dp[k+1][j]) = dp[i][k-1].
	// Then find k_0, it will be fast to find dp[i][j].

	// It's called sliding window because both a and k_0 varies so we have to discard some values and incoporate some values.
	// It contains f(k,b) + k + 1 for all a<=k<=k_0(a,b).
	// This is a quite hard approach, I think it also takes some time for zkw to think through.

  public:
	int getMoneyAmount(int n)
	{
		std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));
		for (int j = 1; j <= n; ++j)
		{
			int k_0 = j - 1;
			std::deque<std::pair<int, int>> queue; // Like a sliding window, it's for finding left.  The second of pairs is ordered.
												   // The front elements of this deque are with smaller values and more close to fall out of window.
			for (int i = j - 1; i > 0; --i)
			{
				while (dp[i][k_0 - 1] > dp[k_0 + 1][j])
				{
					if (!queue.empty() && queue.front().second == k_0)
						queue.pop_front();
					--k_0;
				}

				int num = i + dp[i + 1][j];
				while (!queue.empty() && num < queue.back().first)
				{ // pop all numbers greater than num.
					queue.pop_back();
				}
				queue.emplace_back(num, i);
				int left = queue.front().first;
				int right = dp[i][k_0] + k_0 + 1;
				dp[i][j] = std::min(left, right);
			}
		}
		return dp[1][n];
	}
};
