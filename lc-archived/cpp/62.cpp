////Problem : Unique Paths
////
////Problem Description:
////  
////  A robot is located at the top - left corner of a m x n grid
////  (marked 'Start' in the diagram below).
////  
////  The robot can only move either down or right at any point in 
////  time.The robot is trying to reach the bottom - right corner of 
////  the grid(marked 'Finish' in the diagram below).
////  
////  How many possible unique paths are there ?
////  
////  Example 1:
////  
////  Input: m = 3, n = 2
////  Output : 3
////  Explanation :
////			From the top - left corner, there are a total of 3 ways to reach the bottom - right corner :
////			1. Right->Right->Down
////			2. Right->Down->Right
////			3. Down->Right->Right
////  Example 2 :
////  
////  Input : m = 7, n = 3
////  Output : 28
////  
////  Note :
////  1. m and n will be at most 100.
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//class Solution {
//public:
//	int uniquePaths(int m, int n) {
//		std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
//		for (int i = 0; i<m; ++i)dp[i][0] = 1;
//		for (int i = 0; i<n; ++i)dp[0][i] = 1;
//		for (int i = 1; i<m; ++i) {
//			for (int j = 1; j<n; ++j) {
//				dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
//			}
//		}
//		return dp[m - 1][n - 1];
//	}
//};
//
//int main() {
//	std::vector<std::pair<int, int>> testCase = { {7,3} };
//	std::vector<int> testAns = { 28 };
//	for (int i = 0; i < testCase.size(); ++i) {
//		bool result = Solution().uniquePaths(testCase[i].first, testCase[i].second) == testAns[i];
//		if (result)
//			std::cout << "Test case " << i + 1 << " passed." << std::endl;
//		else
//			std::cout << "Test case " << i + 1 << " failed." << std::endl;
//	}
//	std::cin.get();
//	return 0;
//}