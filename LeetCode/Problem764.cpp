//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <set>
//
//using namespace std;
//class SolutionA
//{
//	// Brute force(TLE!!!)
//public:
//	int orderOfLargestPlusSign(int N, vector<vector<int>> &mines)
//	{
//		int ans = 0;
//		std::set<int> zero_set;
//		for (std::vector<int> &mine : mines)
//			zero_set.insert(mine[0] * N + mine[1]);
//		for (int i = 0; i < N; ++i)
//		{
//			for (int j = 0; j < N; ++j) // For each position (i, j)
//			{
//				if (zero_set.count(i * N + j))
//					continue;
//				int k = 0;
//				//(i,j+k) (i,j-k) (i+k,j) (i-k, j)
//				while ((j - k) >= 0 && (j + k) < N && (i + k) < N && (i - k) >= 0 &&
//					(!zero_set.count(i * N + j + k) && !zero_set.count(i * N + j - k) && !zero_set.count((i - k)*N + j) && !zero_set.count((i + k)*N + j))
//					)
//				{
//					++k;
//				}
//				ans = std::max(ans, k);
//			}
//		}
//		return ans;
//	}
//};
//
//class SolutionB
//{
//public:
//	int orderOfLargestPlusSign(int N, vector<vector<int>> &mines)
//	{
//		int ans = 0;
//		std::set<int> zero_set;
//		std::vector<std::vector<int>> dp(N, std::vector<int>(N, 0));
//
//		for (std::vector<int> &mine : mines)
//			zero_set.insert(mine[0] * N + mine[1]);
//
//		for (int i = 0; i < N; ++i)
//		{
//			int count = 0;
//			for (int j = 0; j < N; ++j)
//			{
//				count = zero_set.count(i * N + j) ? 0 : count + 1;
//				dp[i][j] = count;
//			}
//
//			count = 0;
//			for (int j = N - 1; j >= 0; --j)
//			{
//				count = zero_set.count(i * N + j) ? 0 : count + 1;
//				dp[i][j] = std::min(count, dp[i][j]);
//			}
//		}
//
//		for (int j = 0; j < N; ++j)
//		{
//			int count = 0;
//			for (int i = 0; i < N; ++i)
//			{
//				count = zero_set.count(i * N + j) ? 0 : count + 1;
//				dp[i][j] = std::min(count, dp[i][j]);
//			}
//			count = 0;
//			for (int i = N - 1; i >= 0; --i)
//			{
//				count = zero_set.count(i * N + j) ? 0 : count + 1;
//				dp[i][j] = std::min(count, dp[i][j]);
//				ans = std::max(ans, dp[i][j]);
//			}
//		}
//
//		return ans;
//	}
//};
//
//class SolutionC
//{
//	// Optimized on SolutionB
//	//reference: https://leetcode.com/problems/largest-plus-sign/discuss/113314/javacpython-on2-solution-using-only-one-grid-matrix
//public:
//	int orderOfLargestPlusSign(int N, vector<vector<int>> &mines)
//	{
//		int ans = 0;
//
//		std::vector<std::vector<int>> grid(N, std::vector<int>(N, N));
//
//		for (const std::vector<int> &mine : mines)
//		{
//			grid[mine[0]][mine[1]] = 0;
//		}
//		for (int i = 0; i < N; ++i)
//		{
//			for (int j = 0, k = N - 1, l = 0, r = 0, u = 0, d = 0; j < N - 1; ++j, --k)
//			{
//				grid[i][j] = std::min(grid[i][j], l = (grid[i][j] == 0 ? 0 : l + 1));
//				grid[i][k] = std::min(grid[i][k], r = (grid[i][k] == 0 ? 0 : r + 1));
//				grid[j][i] = std::min(grid[j][i], u = (grid[j][i] == 0 ? 0 : u + 1));
//				grid[k][i] = std::min(grid[k][i], d = (grid[k][i] == 0 ? 0 : d + 1));
//			}
//		}
//		for (const std::vector<int> &vec : grid)
//		{
//			for (int num : vec)
//			{
//				ans = std::max(ans, num);
//			}
//		}
//		return ans;
//	}
//};
//
//class SolutionD
//{
//public:
//	int orderOfLargestPlusSign(int N, vector<vector<int>> &mines)
//	{
//		int ans = 0;
//		std::vector<std::vector<int>> grid(N, std::vector<int>(N, N));
//		std::vector<int> mem(N, -1);
//		for (const std::vector<int> &mine : mines)
//		{
//			grid[mine[0]][mine[1]] = 0;
//		}
//		for (int i = 0; i < N; ++i)
//		{
//			int left = -1;
//			for (int j = 0; j < N; ++j)
//			{
//				if (grid[i][j] == 0)
//				{
//					mem[j] = i;
//					left = j;
//				}
//				else
//					grid[i][j] = std::min(j - left, i - mem[j]);
//			}
//		}
//		mem = std::vector<int>(N, N);
//		for (int i = N - 1; i >= 0; --i)
//		{
//			int right = N;
//			for (int j = N - 1; j >= 0; --j)
//			{
//				if (grid[i][j] == 0) {
//					mem[j] = i;
//					right = j;
//				}
//				else {
//					grid[i][j] = std::min(grid[i][j], std::min(right - j, mem[j] - i));
//					ans = std::max(ans, grid[i][j]);
//				}
//			}
//		}
//		return ans;
//	}
//};
//int main()
//{
//	std::vector < std::pair<int, std::vector<std::vector<int>>>> testCase = { std::make_pair(5,std::vector<std::vector<int>>({{4,2}})) };
//	std::vector<int> testAns = { 2 };
//	for (int i = 0; i < testCase.size(); ++i) {
//		if (SolutionA().orderOfLargestPlusSign(testCase[i].first, testCase[i].second) == testAns[i]) {
//			std::cout << "Test case " << i + 1 << " passed.\n";
//		}
//		else {
//			std::cout << "Test case " << i + 1 << " failed.\n";
//		}
//	}
//	std::cin.get();
//	return 0;
//}