////Problem : Stone Game
////
////Problem Description:
////  Alex and Lee play a game with piles of stones.  There are an even number of piles arranged in a row, 
////  and each pile has a positive integer number of stones piles[i].
////  
////  The objective of the game is to end with the most stones.The total number of stones is odd, so there 
////  are no ties.
////  
////  Alex and Lee take turns, with Alex starting first.Each turn, a player takes the entire pile of stones
////  from either the beginning or the end of the row.This continues until there are no more piles left, at
////  which point the person with the most stones wins.
////  
////  Assuming Alex and Lee play optimally, return True if and only if Alex wins the game.
//
////  Example1:
////  Input: [5,3,4,5]
////  Output: true
////  Explanation :
////  Alex starts first, and can only take the first 5 or the last 5.
////  Say he takes the first 5, so that the row becomes[3, 4, 5].
////  If Lee takes 3, then the board is[4, 5], and Alex takes 5 to win with 10 points.
////  If Lee takes the last 5, then the board is[3, 4], and Alex takes 4 to win with 9 points.
////  This demonstrated that taking the first 5 was a winning move for Alex, so we return true.
//
////  Note:
//// 
////  1.2 <= piles.length <= 500
////  2.piles.length is even.
////  3.1 <= piles[i] <= 500
////  4.sum(piles) is odd.
//
//#include<iostream>
//#include<vector>
//
//#define max(a,b) ((a)>(b)?(a):(b))
//
//class Solution {
//public:
//	// backward induction proved solution or odd or even method.
//	// Try to find the post leetcode877 written by Youjie Zhang.
//	bool stoneGameA(std::vector<int>& piles) {
//		return true;
//	}
//
//    // dynamic programming
//	bool stoneGameB(std::vector<int>& piles) {
//		std::vector<std::vector<int>> dp(piles.size(), std::vector<int>(piles.size(), 0));
//
//		for (int i = 0; i<piles.size(); ++i) {
//			for (int j = i; j<piles.size(); ++j) {
//				if (j == i) {
//					dp[i][j] = piles[i];
//					continue;
//				}
//				dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
//			}
//		}
//		return dp[0][piles.size() - 1];
//	}
//};
//
//int main() {
//	Solution solution;
//	std::vector<std::vector<int>> testCase = { {5,3,4,5} };
//	std::vector<bool> testAns = { true };
//	for (int i = 0; i < testCase.size(); ++i) {
//		bool result = solution.stoneGameA(testCase[i]) == testAns[i];
//		if (result)
//			std::cout << "Test case " << i + 1 << "passed with solution A." << std::endl;
//		else
//			std::cout << "Test case " << i + 1 << "failed with solution A." << std::endl;
//
//		result = solution.stoneGameB(testCase[i]) == testAns[i];
//		if (result)
//			std::cout << "Test case " << i + 1 << "passed with solution B." << std::endl;
//		else
//			std::cout << "Test case " << i + 1 << "failed with solution B." << std::endl;
//	}
//}