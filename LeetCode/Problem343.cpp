////Problem : Integer Break
////
////Problem Description:
////  Given a positive integer n, break it into the sum of at least two positive 
////  integers and maximize the product of those integers. Return the maximum product you can get.
////
////  Example1:
////  Input: 2
////  Output: 1
////  Explanation : 2 = 1 + 1, 1 ¡Á 1 = 1.
////
////  Example2:
////  Input: 10
////  Output: 36
////  Explanation : 10 = 3 + 3 + 4, 3 ¡Á 3 ¡Á 4 = 36.
////
////  Note:
//// 
////  1.You may assume that n is not less than 2 and not larger than 58.
//
//#include<iostream>
//#include<vector>
//
//#define max(a,b) ((a)>(b)?(a):(b))
//
//class Solution {
//public:
//	int integerBreak(int n) {
//		std::vector<int> dp(n + 1, 0);
//		for (int i = 1; i <= n; ++i) {
//			for (int j = 1; j <= i; ++j) {
//				int tmp = j*max(dp[i-j], i-j);
//				dp[i] = max(tmp, dp[i]);
//			}
//		}
//		return dp[n];
//	}
//};
//
//int main() {
//	Solution solution;
//	std::vector<int> testCase = { 2,10 };
//	std::vector<int> testAns = { 1,36 };
//		for (int i = 0; i < testCase.size();++i) {
//			if (solution.integerBreak(testCase[i]) == testAns[i])
//				std::cout << "test case " << testCase[i] << " passed.\n";
//			else
//				std::cout << "test case " << testCase[i] << " failed.\n";
//		}
//	std::cin.get();
//	return 0;
//}