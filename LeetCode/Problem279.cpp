#include<vector>
#include<functional>
#include<numeric>
#include<algorithm>
#include<iostream>

// ref:https://leetcode.com/problems/perfect-squares/discuss/71488/Summary-of-4-different-solutions-(BFS-DP-static-DP-and-mathematics)
//     https://en.wikipedia.org/wiki/Lagrange%27s_four-square_theorem

class SolutionA {
public:
	int numSquares(int n) {
		if (n < 0)return 0;
		std::vector<int> dp(n + 1, n);
		dp[0] = 0;
		for (int i = 0; i <= n; ++i) {
			for (int j = 1; (i + j * j) <= n; ++j) {
				dp[i + j * j] = std::min(dp[i + j * j], dp[i] + 1);
			}
		}
		return dp[n];
	}
};

class SolutionB {
public:
	int numSquares(int n) {
		if (n < 0)return 0;
		std::vector<int> dp(n + 1, n);
		dp[0] = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; (i - j * j) >= 0; ++j) {
				dp[i] = std::min(dp[i], dp[i - j * j] + 1);
			}
		}
		return dp[n];
	}
};

class SolutionC {
	// Store results between test cases,
public:
	int numSquares(int n) {
		static std::vector<int> dp({ 0 });
		if (dp.size() >= n + 1) return dp[n];
		while (dp.size() < n + 1) {
			int tmp = n;
			for (int i = 1; i*i <= dp.size(); ++i) {
				tmp = std::min(tmp, dp[dp.size() - i * i]);
			}
			dp.push_back(tmp + 1);
		}
		return dp[n];
	}
};

class SolutionD {
private:
	bool is_square(int n) {
		if (n < 0) return false;
		int sqrt_n = static_cast<int>(sqrt(n));
		return sqrt_n * sqrt_n == n;
	}
public:
	// According to Lagrange's four-square theorem the result can only be 1, 2, 3 and 4.
	// n == 4^k(8m+7) if n can be decomposed into 4 squares.
	// better logic than below for judging 1 or 2 
	// in (https://leetcode.com/problems/perfect-squares/discuss/71595/Java-use-Lagrange's-four-square-theorem)
	int numSquares(int n) {
		if (n <= 0) return 0;
		if (is_square(n)) return 1;
		// if n%4==0 n/=4
		while (!(n & 3)) n >>= 2;

		// Jude whether n mod 8 is 7
		if ((n & 7) == 7) return 4;
		
		
		for (int i = 1; i*i <= n; ++i) {
			int diff = n - i * i;
			if (is_square(diff)) {
				return 2;
			}
		}
		return 3;
	}
};
int main() {
	std::vector<int> testCase = { 12 };
	std::vector<int> testAns = { 3 };
	for (int i = 0; i < testCase.size(); ++i) {
		bool result = SolutionA().numSquares(testCase[i]) == testAns[i];
		if (result)
			std::cout << "Test case " << i + 1 << " passed with solution A." << std::endl;
		else
			std::cout << "Test case " << i + 1 << " failed with solution A." << std::endl;
	}
	std::cin.get();
	return 0;
}