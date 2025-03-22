////Problem : Minimum Path Sum
////
////Problem Description:
////  Given a m x n grid filled with non-negative numbers, find a path 
////  from top left to bottom right which minimizes the sum of all numbers 
////  along its path.
////  
////  Example:
////  
////  Input:
////  [
////  	[1, 3, 1],
////  	[1, 5, 1],
////  	[4, 2, 1]
////  ]
////  Output : 7
////  Explanation : Because the path 1¡ú3¡ú1¡ú1¡ú1 minimizes the sum.
////  
////  Note :
////  You can only move either down or right at any point in time.
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <cassert>
//#include <algorithm>
//
//class Solution {
//public:
//	int minPathSum(std::vector<std::vector<int>>& grid) {
//		const int row = grid.size();
//		const int col = row != 0 ? grid[0].size() : 0;
//		std::vector<int> dp(col, 0);
//		dp[0] = grid[0][0];
//		for (int i = 1; i < col; ++i)
//			dp[i] = grid[0][i] + dp[i - 1];
//		for (int i = 1; i < row; ++i) {
//			dp[0] += grid[i][0];
//			for (int j = 1; j < col; ++j) {
//				dp[j] = grid[i][j] + std::min(dp[j - 1], dp[j]);
//			}
//		}
//		return dp[col - 1];
//	}
//};
//
//int main() {
//	std::vector<std::vector<std::vector<int>>> testCase = {
//		{
//			{1,3,1},
//			{1,5,1 },
//			{4,2,1}
//		}
//	};
//	std::vector<int> testAns = { 7 };
//	for (int i = 0; i < testCase.size(); ++i) {
//		bool res = Solution().minPathSum(testCase[i]) == testAns[i];
//		if (res) {
//			std::cout << "Test case " << i << " passed.\n";
//		}
//		else {
//			std::cout << "Test case " << i << " failed.\n";
//		}
//	}
//	std::cin.get();
//	return 0;
//}