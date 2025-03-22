////Problem : Length of Longest Fibonacci Subsequence
////
////Problem Description:
////  A sequence X_1, X_2, ..., X_n is fibonacci-like if:
////  
////  n >= 3
////  X_i + X_{ i + 1 } = X_{ i + 2 } for all i + 2 <= n
////  Given a strictly increasing array A of positive integers 
////  forming a sequence, find the length of the longest fibonacci 
////  - like subsequence of A.If one does not exist, return 0.
////  
////  (Recall that a subsequence is derived from another sequence A 
////   by deleting any number of elements(including none) from A, 
////   without changing the order of the remaining elements.For 
////   example, [3, 5, 8] is a subsequence of[3, 4, 5, 6, 7, 8].)
////
////  Example 1:
////  Input: [1, 2, 3, 4, 5, 6, 7, 8]
////  Output : 5
////  Explanation :
////    The longest subsequence that is fibonacci - like : [1, 2, 3, 5, 8].
////
////  Example 2 :
////  Input : [1, 3, 7, 11, 12, 14, 18]
////  Output : 3
////  Explanation :
////    The longest subsequence that is fibonacci - like :
////    [1, 11, 12], [3, 11, 14] or [7, 11, 18].
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//class Solution {
//public:
//	int lenLongestFibSubseq(std::vector<int>& A) {
//		int maxLen = 0;
//		std::vector<int> dp(A.size(), 1);
//		for (int i = 0; i < A.size(); ++i) {
//			for (int j = i - 2; j >= 0; --j) {
//				int diff = A[i] - A[j];
//				int left = j + 1, right = i - 1;
//				while (left <= right) {
//					int mid = (left + right) / 2;
//					if (A[mid] < diff) {
//						left = mid + 1;
//					}
//					else if (A[mid] > diff) {
//						right = mid - 1;
//					}
//					else
//						break;
//				}
//				if (left <= right)// find diff
//					dp[i] = std::max(dp[i], dp[j] + 2);
//			}
//			maxLen = std::max(maxLen, dp[i]);
//		}
//		return maxLen <= 2 ? 0 : maxLen;
//	}
//};
//int main()
//{
//	std::vector < std::vector<int>> testCase = { { 1,3,7,11,12,14,18 } };
//	std::vector<int> testAns = { 3};
//	for (int i = 0; i < testCase.size(); ++i) {
//		if (Solution().lenLongestFibSubseq(testCase[i]) == testAns[i]) {
//			std::cout << "Test case " << i + 1 << " passed.\n";
//		}
//		else {
//			std::cout << "Test case " << i + 1 << " failed.\n";
//		}
//	}
//	std::cin.get();
//	return 0;
//}