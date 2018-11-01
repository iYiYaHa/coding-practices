////Problem : Unique Binary Search Trees
////
////Problem Description:
////  Given n, how many structurally unique BST's (binary search trees) 
////  that store values 1 ... n?
////  
////  Example:
////  
////  Input: 3
////  Output : 5
////  Explanation :
////		Given n = 3, there are a total of 5 unique BST's:
////  
////		1         3     3      2      1
////  	\       /     /      / \      \
////		 3     2     1      1   3      2
////		/     /       \                 \
////		2     1         2                 3
//// References:https://leetcode.com/problems/unique-binary-search-trees/solution/
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <cassert>
//#include <algorithm>
//
//class SolutionA {
//	// Given n consecutive numbers, no matter which certain numbers they are,
//	// the number of binary-search-tree they can form is fixed.
//public:
//	int numTrees(int n) {
//		std::vector<int> dp(n + 1, 0);
//		dp[0] = 1;
//		dp[1] = 1;
//		for (int i = 2; i <= n; ++i) {
//			for (int j = 1; j <= i; ++j) {
//				dp[i] += dp[j - 1] * dp[i - j];
//			}
//		}
//		return dp[n];
//	}
//
//};
//
// class SolutionB {
//	 // recursive solutions with memorization.
// public:
//     int numTrees(int n) {
//         std::vector<std::vector<int>> dp(n+1, std::vector<int>(n+1,-1));
//     	return recursiveCount(1,n,dp);
//     }
// private:
// 	int recursiveCount(int begin, int end, std::vector<std::vector<int>> &dp){
// 		if(begin>=end)
// 			return 1;
//         if(dp[begin][end] != -1)
//             return dp[begin][end];
// 		int sum = 0;
// 		for(int i = begin;i<=end;++i){
// 			sum += recursiveCount(begin,i-1,dp) * recursiveCount(i+1,end,dp);
// 		}
//         dp[begin][end] = sum;
// 		return dp[begin][end];
// 	}
// };
//int main() {
//	std::vector<int> testCase = {1,2,3,10};
//	std::vector<int> testAns = { 1,2,5,16796 };
//	for (int i = 0; i < testCase.size(); ++i) {
//		bool res = SolutionA().numTrees(testCase[i]) == testAns[i];
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