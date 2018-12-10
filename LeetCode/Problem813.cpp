////Problem : 309. Best Time to Buy and Sell Stock with Cooldown
////
////Problem Description:
////  
////  We partition a row of numbers A into at most K adjacent(non - empty) groups, 
////  then our score is the sum of the average of each group.What is the largest 
////  score we can achieve ?
////  
////  Note that our partition must use every number in A, and that scores are not 
////  necessarily integers.
////
////  Example1:
////  Input :
////		A = [9, 1, 2, 3, 9]
////		K = 3
////  Output : 20
////  Explanation :
////		The best choice is to partition A into[9], [1, 2, 3], [9].The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
////		We could have also partitioned A into[9, 1], [2], [3, 9], for example.
////		That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.
////
////  Note:
////	  1.1 <= A.length <= 100.
////	  2.1 <= A[i] <= 10000.
////	  3.1 <= K <= A.length.
//
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//class Solution {
//public:
//	double largestSumOfAverages(std::vector<int>& A, int K) {
//		int n = A.size();
//		std::vector<int> sum(n, 0);
//		std::vector<std::vector<double>> dp(K + 1, std::vector<double>(n, 0));
//		for (int i = 0; i < n; ++i) {
//			sum[i] = (i >= 1 ? sum[i - 1] : 0) + A[i];
//		}
//
//		for (int i = 0; i < n; ++i) {
//			dp[1][i] = sum[i] * 1.0 / (i + 1);
//			for (int k = 2; k <= K; ++k) {
//				dp[k][i] = 0;
//				for (int j = k - 2; j < i; ++j) {
//					dp[k][i] = std::max(dp[k - 1][j] + ((sum[i] - sum[j])*1.0 / (i - j)), dp[k][i]);
//				}
//			}
//		}
//		return dp[K][n - 1];
//	}
//};
//
//int main()
//{
//	std::vector < std::pair<std::vector<int>,int>> testCase = { std::make_pair(std::vector<int>({ 9,1,2,3,9 }),20) };
//	std::vector<int> testAns = { 3 };
//	for (int i = 0; i < testCase.size(); ++i) {
//		if (Solution().largestSumOfAverages(testCase[i].first,testCase[i].second) == testAns[i]) {
//			std::cout << "Test case " << i + 1 << " passed.\n";
//		}
//		else {
//			std::cout << "Test case " << i + 1 << " failed.\n";
//		}
//	}
//	std::cin.get();
//	return 0;
//}