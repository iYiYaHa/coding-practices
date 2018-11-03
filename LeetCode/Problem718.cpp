////Problem : Maximum Length of Repeated Subarray
////
////  Problem Description:
////		Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.
//// 
////  Example 1:
////		Input:
////			A: [1, 2, 3, 2, 1]
////			B : [3, 2, 1, 4, 7]
////		Output : 3
////		Explanation :
////			The repeated subarray with maximum length is[3, 2, 1].
////	Note:
////		1. 1 <= len(A), len(B) <= 1000
////		2. 0 <= A[i], B[i] < 100
//#include <iostream>
//#include <vector>
//#include <string>
//
//class Solution {
//public:
//	int findLength(std::vector<int>& A, std::vector<int>& B) {
//		std::vector<std::vector<int>> dp(A.size() + 1, std::vector<int>(B.size() + 1, 0));
//		int max = 0;
//		for (int i = 1; i <= A.size(); ++i) {
//			for (int j = 1; j <= B.size(); ++j) {
//				dp[i][j] = A[i - 1] == B[j - 1] ? dp[i - 1][j - 1] + 1 : 0;
//				max = max > dp[i][j] ? max : dp[i][j];
//			}
//		}
//		return max;
//	}
//};
//
//class SolutionB {
//public:
//	// DP with space optimized.
//	int findLength(std::vector<int>& A, std::vector<int>& B) {
//		std::vector<int> dp(B.size() + 1, 0);
//		int max = 0;
//		for (int i = 1; i <= A.size(); ++i) {
//			for (int j = B.size(); j > 0; --j) {
//				dp[j] = A[i - 1] == B[j - 1] ? dp[j - 1] + 1 : 0;
//				max = max > dp[j] ? max : dp[j];
//			}
//		}
//		return max;
//	}
//};
//int main() {
//	std::vector<std::pair<std::vector<int>, std::vector<int>>> testCase = { {{3,2,1,4,7},{1,2,3,2,1}} };
//	std::vector<int> testAns = { 3 };
//	for (int i = 0; i < testCase.size(); ++i) {
//		bool result = Solution().findLength(testCase[i].first, testCase[i].second) == testAns[i];
//		if (result)
//			std::cout << "Test case " << i + 1 << " passed." << std::endl;
//		else
//			std::cout << "Test case " << i + 1 << " failed." << std::endl;
//	}
//	std::cin.get();
//	return 0;
//}