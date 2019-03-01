//#include<vector>
//#include<functional>
//#include<numeric>
//#include<algorithm>
//#include<iostream>
//#include<queue>
//#include<utility>
//
//// ref:https://leetcode.com/problems/perfect-squares/discuss/71488/Summary-of-4-different-solutions-(BFS-DP-static-DP-and-mathematics)
////     https://en.wikipedia.org/wiki/Lagrange%27s_four-square_theorem
//
//class SolutionA {
//public:
//	int numSquares(int n) {
//		if (n < 0)return 0;
//		std::vector<int> dp(n + 1, n);
//		dp[0] = 0;
//		for (int i = 0; i <= n; ++i) {
//			for (int j = 1; (i + j * j) <= n; ++j) {
//				dp[i + j * j] = std::min(dp[i + j * j], dp[i] + 1);
//			}
//		}
//		return dp[n];
//	}
//};
//
//class SolutionB {
//public:
//	int numSquares(int n) {
//		if (n < 0)return 0;
//		std::vector<int> dp(n + 1, n);
//		dp[0] = 0;
//		for (int i = 1; i <= n; ++i) {
//			for (int j = 1; (i - j * j) >= 0; ++j) {
//				dp[i] = std::min(dp[i], dp[i - j * j] + 1);
//			}
//		}
//		return dp[n];
//	}
//};
//
//class SolutionC {
//	// Store results between test cases,
//public:
//	int numSquares(int n) {
//		static std::vector<int> dp({ 0 });
//		if (dp.size() >= n + 1) return dp[n];
//		while (dp.size() < n + 1) {
//			int tmp = n;
//			for (int i = 1; i*i <= dp.size(); ++i) {
//				tmp = std::min(tmp, dp[dp.size() - i * i]);
//			}
//			dp.push_back(tmp + 1);
//		}
//		return dp[n];
//	}
//};
//
//class SolutionD {
//private:
//	bool is_square(int n) {
//		if (n < 0) return false;
//		int sqrt_n = static_cast<int>(sqrt(n));
//		return sqrt_n * sqrt_n == n;
//	}
//public:
//	// According to Lagrange's four-square theorem the result can only be 1, 2, 3 and 4.
//	// n == 4^k(8m+7) if n can be decomposed into 4 squares.
//	// better logic than below for judging 1 or 2 
//	// in (https://leetcode.com/problems/perfect-squares/discuss/71595/Java-use-Lagrange's-four-square-theorem)
//	int numSquares(int n) {
//		if (n <= 0) return 0;
//		if (is_square(n)) return 1;
//		// if n%4==0 n/=4
//		while (!(n & 3)) n >>= 2;
//
//		// Jude whether n mod 8 is 7
//		if ((n & 7) == 7) return 4;
//		
//		
//		for (int i = 1; i*i <= n; ++i) {
//			int diff = n - i * i;
//			if (is_square(diff)) {
//				return 2;
//			}
//		}
//		return 3;
//	}
//};
//
//class SolutionE {
//	// DFS
//private:
//	int helper(int n, int depth, int min) {
//		if (depth >= min) return depth;// pruning
//		if (static_cast<int>(sqrt(n))*static_cast<int>(sqrt(n)) == n) return 1;
//		for (int i = 1; i*i <= n; ++i) {
//			int tmp = 1 + helper(n - i * i, depth + 1, min);
//			min = std::min(tmp, min);
//		}
//		return min;
//	}
//public:
//	int numSquares(int n) {
//		if (n <= 0) return 0;
//		return helper(n, 0, n);
//	}
//};
//
//class SolutionF {
//	// BFS
//	// Starting from n, in a top-down manner which contains many redundant computation
//public:
//	int numSquares(int n) {
//		if (n <= 0) return 0;
//		std::queue<std::pair<int, int>> queue;
//		queue.push(std::make_pair(0, n));
//		while (!queue.empty()) {
//			int level = queue.front().first;
//			int num = queue.front().second;
//			queue.pop();
//			if (static_cast<int>(sqrt(num))*static_cast<int>(sqrt(num)) == num) return level + 1;
//			for (int i = 1; i*i < num; ++i) {
//				queue.push(std::make_pair(level + 1, num - i * i));
//			}
//		}
//		return 0;
//	}
//};
//class SolutionG {
//	// Another way to perform BFS, starting from all squares <= n as first-level nodes.
//public:
//	int numSquares(int n) {
//		std::queue<int> queue;
//		std::vector<int> cntPerfectSquares(n + 1, 0);
//		std::vector<int> perfectSquares;
//		for (int i = 1; i*i <= n; ++i) {
//			perfectSquares.push_back(i*i);
//			cntPerfectSquares[i*i] = 1;
//		}
//		if (perfectSquares.back() == n) return 1;
//
//		for (const int &i : perfectSquares) {
//			queue.push(i);
//		}
//
//		int level = 1;
//		while (!queue.empty()) {
//			int currLevelSize = queue.size();
//			++level;
//			for (int i = 1; i <= currLevelSize; ++i) {
//				int num = queue.front();
//				queue.pop();
//				for (const int &square : perfectSquares) {
//					if (num + square == n)
//						return level;
//					else if (num + square < n && cntPerfectSquares[num + square] == 0) {
//						queue.push(num + square);
//						cntPerfectSquares[num + square] = level;
//					}
//					else if (num + square > n) {
//						break;
//					}
//				}
//			}
//		}
//		return 0;
//	}
//};
//int main() {
//	std::vector<int> testCase = { 12 };
//	std::vector<int> testAns = { 3 };
//	for (int i = 0; i < testCase.size(); ++i) {
//		bool result = SolutionA().numSquares(testCase[i]) == testAns[i];
//		if (result)
//			std::cout << "Test case " << i + 1 << " passed with solution A." << std::endl;
//		else
//			std::cout << "Test case " << i + 1 << " failed with solution A." << std::endl;
//	}
//	std::cin.get();
//	return 0;
//}